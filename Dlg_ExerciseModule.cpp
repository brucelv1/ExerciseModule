#include "Dlg_ExerciseModule.h"
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <QtGui/QMessageBox>
#include <QtCore/QString>
#include <algorithm>
#include <Windows.h> // DLL

Dlg_ExerciseModule::Dlg_ExerciseModule(unsigned char* nameSharedMem, size_t lenSharedMem, QWidget* parent /*= NULL*/ )
	: QDialog(parent)
	, _armBand(new SJTArmBand())
	, _mClassifier(nullptr)
	, _mCreateClassifierFunc(nullptr)
	, _mDestroyClassifierFunc(nullptr)
	, _ucpNameSharedMem(nameSharedMem)
	, _stLenSharedMem(lenSharedMem)
	, _tableModel(new QStandardItemModel(this))
	, _mSingleDuration(6)
{
	setupUi(this);
	_initTableView();
	qTimer = new QTimer(this);
	connect(qTimer, SIGNAL(timeout()), this, SLOT(_qTimer_timeout()));
	_updateGUI();
}

Dlg_ExerciseModule::~Dlg_ExerciseModule()
{
	_mThread.join();
	if (_mClassifier != nullptr)
	{
		_mDestroyClassifierFunc(_mClassifier);
	}
}

void Dlg_ExerciseModule::_threadSend( Dlg_ExerciseModule* dtm, std::vector<int> testSeries)
{
	using namespace boost::chrono;

	// timing
	duration<double> time_span;
	steady_clock::time_point t1, t2;

	// 臂带一开始不能正常读数，先等待1000ms
	::Sleep(1000);

	// counting
	int progress = 0;
	int total_num = testSeries.size();
	
	// testing series
	for (int i=0; i<total_num; i++)
	{
		// get command and set hint hand
		int command = testSeries[i];
		std::cout << "command: " << command << "  ";
		dtm->_clearHintHand();
		::Sleep(20);
		dtm->_setHintHand(command);

		// main module processing bar
		unsigned char main_module_processing = 0;
		dtm->_ucpNameSharedMem[6] = main_module_processing;

		// 读秒准备：3秒
		t1 = steady_clock::now();
		do 
		{
			::Sleep(250);
			t2 = steady_clock::now();
			time_span = duration_cast<duration<double> > (t2-t1);

			if (time_span.count() <= 1) {
				std::cout << "3 ";
				dtm->_ucpNameSharedMem[5] = 3;// set memory to 3
			}
			else if (time_span.count() <= 2) {
				std::cout << "2 ";
				dtm->_ucpNameSharedMem[5] = 2;// set memory to 2
			}
			else if (time_span.count() <= 3) {
				std::cout << "1 ";
				dtm->_ucpNameSharedMem[5] = 1;// set memory to 1
			}
			else {
				std::cout << "0\n";
				dtm->_ucpNameSharedMem[5] = 0;// set memory to 0
				break;
			}
		} while (1);
		
		// statistics
		int cnt = 0;
		int right = 0;
		int firstHit = 0;
		bool has1stHit = false;
		int rightAfterFirst = 0;

		// sampling, wait for duration
		t1 = steady_clock::now();
		int sampleIdx = 0;
		int winLength = dtm->_mClassifier->GetWindowLength();
		do 
		{
			// data query
			if(dtm->_armBand->IsConnected())
			{
				dtm->_armBandData.push_back(dtm->_armBand->GetDataVector());
			}

			// 凑够了一个窗长，做一次预测
			if (dtm->_armBandData.size() == winLength)
			{
				int predict = dtm->_mClassifier->Predict(dtm->_armBandData);
				
				cnt++;
				/*if (predict == command)
				{
					if (has1stHit==false)
					{
						firstHit = cnt;
						has1stHit = true;
					}
					right++;
				}*/
				dtm->_setExerciseHand(predict, cnt);

				dtm->_armBandData.clear();
			}

			// yield the CPU
			::Sleep(1);

			t2 = steady_clock::now();
			time_span = duration_cast<duration<double> > (t2-t1);
			sampleIdx+=1;
			// update main module
			main_module_processing = 100 * time_span.count() / dtm->_mSingleDuration;
			dtm->_ucpNameSharedMem[6] = main_module_processing;
		} while (time_span.count() < dtm->_mSingleDuration);

		std::cout << "count: " << cnt << "   ";
		std::cout << "rate: " << right*1.0 / cnt << std::endl;

		// statistics
		dtm->_predictPerAction.push_back(std::make_pair(command, cnt));
		dtm->_rightPrdtPerAction.push_back(right);
		dtm->_firstHitDelay.push_back((firstHit-1)*winLength);
		dtm->_holdStability.push_back(right*1.0/(cnt-firstHit+1));
		
		progress+=1;
		dtm->processingBarVal = 100*progress/total_num;
	}

	// after test series, let hint hand get back to REST position
	dtm->_clearHintHand();
	return;
}

void Dlg_ExerciseModule::_qTimer_timeout()
{
	//progressBar->setValue(processingBarVal);
	////std::cout << "process: " << _ucpNameSharedMem[6] << std::endl;
	////progressBar->setValue(_ucpNameSharedMem[6]);
}

void Dlg_ExerciseModule::on_BtnOpenPlugin_clicked()
{
	QString dll_name = QFileDialog::getOpenFileName(this,
		tr("Import Classifier Plug-in"), 
		"",
		tr("Classifier (*.dll)"), 
		0);

	if (!dll_name.isNull())
	{
		LEPluginStatus->setText(dll_name);

		HINSTANCE hGetProcIDDLL = LoadLibraryA(dll_name.toStdString().c_str());
		if ( !hGetProcIDDLL )
		{
			QMessageBox::information(NULL, "Warning", "Cannot load the dynamic library. Please try again", QMessageBox::Ok);
			return;
		}

		_mCreateClassifierFunc = (CreateClassifier)GetProcAddress(hGetProcIDDLL, "CreateClassifier");
		_mDestroyClassifierFunc = (DestroyClassifier)GetProcAddress(hGetProcIDDLL, "DestroyClassifier");
		if (!_mCreateClassifierFunc || !_mDestroyClassifierFunc)
		{
			QMessageBox::information(NULL, "Warning", "Load Error. Please check your DLL and try again", QMessageBox::Ok);
			return;
		}

		_mClassifier = _mCreateClassifierFunc();
		_updateGUI();
	}
	else
	{
		QMessageBox::information(NULL, "Warning", "Classifier cannot be null. Please try again", QMessageBox::Ok);
		return;
	}
}

void Dlg_ExerciseModule::on_BtnImportConfig_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Import Training Configuration File"), 
		"",
		tr("Config Files (*.json)"), 
		0);

	if (!filename.isNull())
	{
		LEConfigPath->setText(filename);
		_mTrainConfigPath = filename.toStdString();
		BtnImportConfig->setEnabled(false);

		// read config file, and generate label vector
		_parseTrainConfig();
		// initialize comboBox of return action
		_initReturnActionCBBOX();
	}
}

void Dlg_ExerciseModule::on_BtnImportData_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Import Training Data File"), 
		"",
		tr("Data Files (*.txt)"), 
		0);

	if (!filename.isNull())
	{
		// generate the label vector
		std::vector<int> labelVec;
		for (size_t i=0; i<_commandVec.size(); i++)
		{
			size_t tsp = _commandVec[i]->TotalSample;
			int label = _commandVec[i]->Command;
			for (size_t j=0; j<tsp; j++)
			{
				labelVec.push_back(label);
			}
		}

		// read raw data
		std::vector<std::vector<double> > trainData;
		std::ifstream raw_data(filename.toStdString());

		std::vector<double> data_tmp(8,0);
		std::string val;
		while(raw_data.good())
		{
			for (int i=0; i<8; i++)
			{
				raw_data >> val;
				data_tmp[i] = std::atof(val.c_str());
			}
			trainData.push_back(data_tmp);
		}

		int num_fea, num_label;
		_mClassifier->AddFeatureLabelFromData(trainData,labelVec,&num_fea,&num_label);
		char info[200];
		sprintf_s(info,"%d feature vectors and %d labels in total.", num_fea, num_label);
		LEDataPath->setText(QString(info));
	}
}

void Dlg_ExerciseModule::on_BtnCreateClassifier_clicked()
{
	// generate a classifier by its specific logic
	if(_mClassifier->GenerateModel()==true)
	{
		string name = _mClassifier->GetName();
		name += " model is generated.";
		LEClassifierStatus->setText(name.c_str());
		return;
	}
	else
	{
		QMessageBox::information(NULL, "Information", "Fail to generate the model.", QMessageBox::Ok);
		LEClassifierStatus->setText("Failed, please try again.");
		return;
	}
}

void Dlg_ExerciseModule::on_BtnSaveClassifier_clicked()
{
	QString dirname = QFileDialog::getExistingDirectory( this );

	if (!dirname.isNull())
	{
		LEClassifierSaveStatus->setText(dirname);
		dirname.replace("\\","\\\\");
		_mClassifier->SaveModelToDisk(dirname.toStdString());
	}
}

void Dlg_ExerciseModule::on_Btn_Connect_clicked()
{
	std::string strCom = cbBox_Armband->currentText().toStdString();
	int nCOM = std::atoi( (strCom.substr(3,strCom.size()-3)).c_str() );

	if(_armBand->Connect(nCOM)==false)
	{
		LE_Armband_Status->setText("Connection Failed.");
		return;
	}

	// 硬件刚连接时可能存在读数全是0的情况，这里做个检查
	vector<double> armband_data = _armBand->GetDataVector();
	double sum = 0;
	for (size_t i=0; i<armband_data.size(); i++)
	{
		sum+=armband_data[i];
	}
	while(sum == 0) // 臂带还没有开始工作，数据全是0
	{
		::Sleep(200);
		armband_data = _armBand->GetDataVector();
		sum = 0;
		for (size_t i=0; i<armband_data.size(); i++)
		{
			sum+=armband_data[i];
		}
	}

	// 臂带已经开始正常采集数据
	LE_Armband_Status->setText("Connection Successful.");
}

void Dlg_ExerciseModule::on_Btn_ApplyFingerReturn_clicked()
{
	QString action = cbBoxReturnAction->currentText();
	LE_ReturnAction->setText(action);

	for (size_t i=0; i<_commandVec.size(); i++)
	{
		if(_commandVec[i]->Name == action.toStdString())
		{
			unsigned char cmd = _commandVec[i]->Command % 256;
			_ucpNameSharedMem[9] = cmd;
		}
	}
}

void Dlg_ExerciseModule::on_Btn_StartExercise_clicked()
{
	// initiate processing bar and start timer
	processingBarVal = 0;
	if(qTimer->isActive())
		qTimer->stop();
	qTimer->start(200);

	_mSingleDuration=spinB_ActionDuration->value();

	// generate test series and shuffle it
	std::vector<int> testSeries;

	std::vector<int> classLabel = _mClassifier->GetClassVector();

	for(int i=1; i<=spinB_ActionTimes->value(); i++)
	{
		testSeries.insert(testSeries.end(), classLabel.begin(), classLabel.end());
	}
	// shuffle
	std::random_shuffle(testSeries.begin(), testSeries.end());

	// clear statistics
	_predictPerAction.clear();
	_rightPrdtPerAction.clear();
	_firstHitDelay.clear();
	_holdStability.clear();

	// start testing thread
	_mThread = boost::thread(boost::bind(&(Dlg_ExerciseModule::_threadSend),this,testSeries));
}

void Dlg_ExerciseModule::on_Btn_CreateReport_clicked()
{

}

void Dlg_ExerciseModule::on_BtnExportReport_clicked()
{

}


void Dlg_ExerciseModule::_updateGUI()
{
	// if no classifier, all button except BtnOpenPlugin should be disabled
	if(_mClassifier == nullptr)
	{
		BtnOpenPlugin->setEnabled(true);
		BtnImportConfig->setEnabled(false);
		BtnImportData->setEnabled(false);
		BtnCreateClassifier->setEnabled(false);
		BtnSaveClassifier->setEnabled(false);
		Btn_Connect->setEnabled(false);
		Btn_StartExercise->setEnabled(false);
		Btn_CreateReport->setEnabled(false);
		BtnExportReport->setEnabled(false);
	}
	else
	{
		BtnOpenPlugin->setEnabled(false);
		BtnImportConfig->setEnabled(true);
		BtnImportData->setEnabled(true);
		BtnCreateClassifier->setEnabled(true);
		BtnSaveClassifier->setEnabled(true);
		Btn_Connect->setEnabled(true);
		Btn_StartExercise->setEnabled(true);
		Btn_CreateReport->setEnabled(true);
		BtnExportReport->setEnabled(true);
	}
}

void Dlg_ExerciseModule::_parseTrainConfig()
{
	using namespace boost::property_tree;
	ptree root;

	try
	{
		// load the json file in this ptree
		read_json(_mTrainConfigPath,root);
	}
	catch (json_parser::json_parser_error& e)
	{
		std::cout << "Error: Invalid JSON file!" << std::endl;
		std::cout << "[Info] " << e.what() << std::endl;
		system("pause");
		return;
	}

	std::string _type = root.get<std::string>("type","");
	if(_type != "Training Series")
	{
		QMessageBox::warning(NULL, "warning", "Invalid configuration file.", QMessageBox::Ok);
		return;
	}

	ptree Actions = root.get_child("actions");
	std::vector< std::shared_ptr<_commandInfo> > InfoVec;
	for (ptree::iterator it=Actions.begin(); it!=Actions.end(); it++)
	{
		std::string name = it->second.get<std::string>("name");
		int command = it->second.get<int>("command");
		size_t dura = it->second.get<size_t>("duration");
		size_t smRt = it->second.get<size_t>("sample_rate");
		size_t tSp = it->second.get<size_t>("total_sample");
		std::shared_ptr<_commandInfo> cinfo(new _commandInfo());
		cinfo->Name = name;
		cinfo->Command = command;
		cinfo->Duration = dura;
		cinfo->SampleRate = smRt;
		cinfo->TotalSample = tSp;
		InfoVec.push_back(cinfo);
	}

	_commandVec.clear();
	_commandVec = InfoVec;
}

void Dlg_ExerciseModule::_initTableView()
{
	_tableModel->setHorizontalHeaderItem(0,new QStandardItem("Action"));
	_tableModel->setHorizontalHeaderItem(1,new QStandardItem("Correctness"));
	_tableModel->setHorizontalHeaderItem(2,new QStandardItem("First Hit Delay"));
	_tableModel->setHorizontalHeaderItem(3,new QStandardItem("Stability"));

	// bind the model with the view
	tbView_Report->setModel(_tableModel);

	// set read-only
	tbView_Report->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Dlg_ExerciseModule::_setHintHand(int command)
{
	_ucpNameSharedMem[10] = 1;
	// parse command
	unsigned char byte0 = command % 256;
	unsigned char byte1 = (command >> 8) % 256;
	unsigned char byte2 = 0; // not used yet
	unsigned char byte3 = 0; // not used yet

	_ucpNameSharedMem[14] = byte0;
	_ucpNameSharedMem[13] = byte1;
	_ucpNameSharedMem[12] = byte2; // not used yet
	_ucpNameSharedMem[11] = byte3; // not used yet
}

void Dlg_ExerciseModule::_setExerciseHand(int predict, int idx_prdt)
{
	_ucpNameSharedMem[7] = idx_prdt;
	_ucpNameSharedMem[8] = predict<256 ? 1 : 2; // 1: finger, 2: wrist

	// parse command
	unsigned char byte0 = predict % 256;
	unsigned char byte1 = (predict >> 8) % 256;
	unsigned char byte2 = 0; // not used yet
	unsigned char byte3 = 0; // not used yet

	_ucpNameSharedMem[4] = byte0;
	_ucpNameSharedMem[3] = byte1;
	_ucpNameSharedMem[2] = byte2; // not used yet
	_ucpNameSharedMem[1] = byte3; // not used yet
}

void Dlg_ExerciseModule::_clearHintHand()
{
	_ucpNameSharedMem[15] = 1;
}

void Dlg_ExerciseModule::_initReturnActionCBBOX()
{
	std::vector<string> actions;
	for (size_t i=0; i<_commandVec.size(); i++)
	{
		// skip the REST and wrist actions
		if(_commandVec[i]->Command == 0 || _commandVec[i]->Command >= 256)
			continue;

		string action = _commandVec[i]->Name;
		actions.push_back(action);
	}
	std::sort(actions.begin(), actions.end());
	actions.erase(std::unique(actions.begin(), actions.end()),actions.end());

	for (size_t i=0; i<actions.size(); i++)
	{
		cbBoxReturnAction->addItem(QString(actions[i].c_str()));
	}
}
