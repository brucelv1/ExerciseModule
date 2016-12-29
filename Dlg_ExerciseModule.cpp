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
	qTimer = new QTimer(this);
	connect(qTimer, SIGNAL(timeout()), this, SLOT(_qTimer_timeout()));
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
		// get command
		int command = testSeries[i];
		std::cout << "command: " << command << "  ";
		// parse command
		unsigned char byte0 = command % 256;
		unsigned char byte1 = (command >> 8) % 256;
		unsigned char byte2 = 0; // not used yet
		unsigned char byte3 = 0; // not used yet
		// write shared memory
		dtm->_ucpNameSharedMem[4] = byte0;
		dtm->_ucpNameSharedMem[3] = byte1;
		dtm->_ucpNameSharedMem[2] = byte2; // not used yet
		dtm->_ucpNameSharedMem[1] = byte3; // not used yet

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
		int cnt = 0; dtm->_ucpNameSharedMem[7]=cnt;
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
				
				cnt++; dtm->_ucpNameSharedMem[7]=cnt;
				if (predict == command)
				{
					if (has1stHit==false)
					{
						firstHit = cnt;
						has1stHit = true;
					}
					right++;
				}

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

	// after test series, let virtual hand get back to REST position
	// write shared memory
	dtm->_ucpNameSharedMem[4] = 0;
	dtm->_ucpNameSharedMem[3] = 0;
	dtm->_ucpNameSharedMem[2] = 0; // not used yet
	dtm->_ucpNameSharedMem[1] = 0; // not used yet
	return;
}

void Dlg_ExerciseModule::_qTimer_timeout()
{
	//progressBar->setValue(processingBarVal);
	////std::cout << "process: " << _ucpNameSharedMem[6] << std::endl;
	////progressBar->setValue(_ucpNameSharedMem[6]);
}

void Dlg_ExerciseModule::on_Btn_Do_clicked()
{
	int command = spinBox->value();
	_ucpNameSharedMem[7]+=1;
	_ucpNameSharedMem[8] = command<256 ? 1 : 2; // 1: finger, 2: wrist
	// parse command
	unsigned char byte0 = command % 256;
	unsigned char byte1 = (command >> 8) % 256;
	unsigned char byte2 = 0; // not used yet
	unsigned char byte3 = 0; // not used yet

	_ucpNameSharedMem[4] = byte0;
	_ucpNameSharedMem[3] = byte1;
	_ucpNameSharedMem[2] = byte2; // not used yet
	_ucpNameSharedMem[1] = byte3; // not used yet
}

void Dlg_ExerciseModule::on_Btn_Clear_clicked()
{
	// parse command
	unsigned char byte0 = 0;
	unsigned char byte1 = 0;
	unsigned char byte2 = 0; // not used yet
	unsigned char byte3 = 0; // not used yet

	_ucpNameSharedMem[4] = byte0;
	_ucpNameSharedMem[3] = byte1;
	_ucpNameSharedMem[2] = byte2; // not used yet
	_ucpNameSharedMem[1] = byte3; // not used yet
	_ucpNameSharedMem[7] = 0;
}

void Dlg_ExerciseModule::on_Btn_Set_clicked()
{
	_ucpNameSharedMem[9] = spinBoxFingerReturn->value();
}
