#ifndef _DLG_EXERCISE_MODULE_
#define _DLG_EXERCISE_MODULE_

#include <QtGui/QDialog>
#include "GUI/ui_ExerciseModule.h"
#include <deque>
#include "HelperArmBand.h"
#include <boost/thread.hpp>
#include <QtCore/QTimer>
#include "ClassifierBase.h"
#include <QtGui/QAbstractItemView>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>

class Dlg_ExerciseModule : public QDialog, public Ui_ExerciseModule
{
	Q_OBJECT
private:
	// use int to store command
	// 0: rest
	// 1: thumb, 2: index, 4: middle, 8: ring, 16: little, 32: OpenHand
	// 256: shangqie, 512: xiaqie
	// 1024: neifan, 2048: waifan
	// 4096: neixuan, 8192: waixuan
	// 16384: shenzhou, 32768: quzhou
	class _commandInfo
	{
	public:
		std::string Name;
		int         Command;
		size_t      Duration;
		size_t      SampleRate;
		size_t      TotalSample;
		_commandInfo() 
			: Name("")
			, Command(0)
			, Duration(0)
			, SampleRate(0)
			, TotalSample(0)
		{}
	};
	std::vector< std::shared_ptr<_commandInfo> > _commandVec;

	// config file paths
	std::string _mTrainConfigPath;

	// ArmBand
	SJTArmBand* _armBand;
	std::vector<std::vector<double> > _armBandData;

	// thread: get data, send command, ...
	boost::thread _mThread;
	// single action duration, in second, used in thread
	// default: 6s
	size_t _mSingleDuration;

	// Timer, for processing bar
	QTimer* qTimer;
	int processingBarVal;

	// Classifier
	ClassifierBase* _mClassifier;
	typedef ClassifierBase* (*CreateClassifier)();
	typedef void (*DestroyClassifier)(ClassifierBase*);
	CreateClassifier _mCreateClassifierFunc;
	DestroyClassifier _mDestroyClassifierFunc;

	// Shared memory
	unsigned char* _ucpNameSharedMem;
	size_t _stLenSharedMem;

	// Statistics
	// 1 每个动作对应的总预测次数 <command, predict>
	std::vector< std::pair<int, int> > _predictPerAction;
	// 2 每个动作正确的预测次数
	std::vector<int> _rightPrdtPerAction;
	// 3 第一次预测正确对应的时间延迟
	std::vector<int> _firstHitDelay;
	// 4 第一次预测正确后，动作保持准确率
	std::vector<float> _holdStability;

	// Table model
	QStandardItemModel* _tableModel;

public:
	Dlg_ExerciseModule(unsigned char* nameSharedMem, size_t lenSharedMem, QWidget* parent = NULL);
	~Dlg_ExerciseModule();

private:

	static void _threadSend(Dlg_ExerciseModule* dtm, std::vector<int> testSeries);

public slots:
	void on_Btn_Do_clicked();
	void on_Btn_Clear_clicked();
	void on_Btn_Set_clicked();

private slots:
	void _qTimer_timeout();
};

#endif // _DLG_EXERCISE_MODULE_