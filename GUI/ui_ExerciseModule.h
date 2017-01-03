/********************************************************************************
** Form generated from reading UI file 'ExerciseModule.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXERCISEMODULE_H
#define UI_EXERCISEMODULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExerciseModule
{
public:
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *BtnOpenPlugin;
    QLineEdit *LEPluginStatus;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *BtnImportConfig;
    QLineEdit *LEConfigPath;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *BtnImportData;
    QLineEdit *LEDataPath;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *BtnCreateClassifier;
    QLineEdit *LEClassifierStatus;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *BtnSaveClassifier;
    QLineEdit *LEClassifierSaveStatus;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbBox_Armband;
    QPushButton *Btn_Connect;
    QLabel *label_2;
    QLineEdit *LE_Armband_Status;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinB_ActionTimes;
    QLabel *label_4;
    QSpinBox *spinB_ActionDuration;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *Btn_StartExercise;
    QProgressBar *progressBar;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QTableView *tbView_Report;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Btn_CreateReport;
    QPushButton *BtnExportReport;

    void setupUi(QDialog *ExerciseModule)
    {
        if (ExerciseModule->objectName().isEmpty())
            ExerciseModule->setObjectName(QString::fromUtf8("ExerciseModule"));
        ExerciseModule->resize(525, 550);
        ExerciseModule->setMinimumSize(QSize(525, 550));
        ExerciseModule->setMaximumSize(QSize(10000, 10000));
        horizontalLayout_13 = new QHBoxLayout(ExerciseModule);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        BtnOpenPlugin = new QPushButton(ExerciseModule);
        BtnOpenPlugin->setObjectName(QString::fromUtf8("BtnOpenPlugin"));

        horizontalLayout_7->addWidget(BtnOpenPlugin);

        LEPluginStatus = new QLineEdit(ExerciseModule);
        LEPluginStatus->setObjectName(QString::fromUtf8("LEPluginStatus"));

        horizontalLayout_7->addWidget(LEPluginStatus);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        BtnImportConfig = new QPushButton(ExerciseModule);
        BtnImportConfig->setObjectName(QString::fromUtf8("BtnImportConfig"));

        horizontalLayout_8->addWidget(BtnImportConfig);

        LEConfigPath = new QLineEdit(ExerciseModule);
        LEConfigPath->setObjectName(QString::fromUtf8("LEConfigPath"));
        LEConfigPath->setReadOnly(true);

        horizontalLayout_8->addWidget(LEConfigPath);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        BtnImportData = new QPushButton(ExerciseModule);
        BtnImportData->setObjectName(QString::fromUtf8("BtnImportData"));

        horizontalLayout_9->addWidget(BtnImportData);

        LEDataPath = new QLineEdit(ExerciseModule);
        LEDataPath->setObjectName(QString::fromUtf8("LEDataPath"));
        LEDataPath->setReadOnly(true);

        horizontalLayout_9->addWidget(LEDataPath);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        BtnCreateClassifier = new QPushButton(ExerciseModule);
        BtnCreateClassifier->setObjectName(QString::fromUtf8("BtnCreateClassifier"));

        horizontalLayout_10->addWidget(BtnCreateClassifier);

        LEClassifierStatus = new QLineEdit(ExerciseModule);
        LEClassifierStatus->setObjectName(QString::fromUtf8("LEClassifierStatus"));

        horizontalLayout_10->addWidget(LEClassifierStatus);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        BtnSaveClassifier = new QPushButton(ExerciseModule);
        BtnSaveClassifier->setObjectName(QString::fromUtf8("BtnSaveClassifier"));

        horizontalLayout_11->addWidget(BtnSaveClassifier);

        LEClassifierSaveStatus = new QLineEdit(ExerciseModule);
        LEClassifierSaveStatus->setObjectName(QString::fromUtf8("LEClassifierSaveStatus"));
        LEClassifierSaveStatus->setReadOnly(true);

        horizontalLayout_11->addWidget(LEClassifierSaveStatus);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_11);

        groupBox = new QGroupBox(ExerciseModule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbBox_Armband = new QComboBox(groupBox);
        cbBox_Armband->setObjectName(QString::fromUtf8("cbBox_Armband"));

        horizontalLayout->addWidget(cbBox_Armband);

        Btn_Connect = new QPushButton(groupBox);
        Btn_Connect->setObjectName(QString::fromUtf8("Btn_Connect"));

        horizontalLayout->addWidget(Btn_Connect);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        LE_Armband_Status = new QLineEdit(groupBox);
        LE_Armband_Status->setObjectName(QString::fromUtf8("LE_Armband_Status"));

        horizontalLayout->addWidget(LE_Armband_Status);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ExerciseModule);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinB_ActionTimes = new QSpinBox(groupBox_2);
        spinB_ActionTimes->setObjectName(QString::fromUtf8("spinB_ActionTimes"));
        spinB_ActionTimes->setMinimum(1);
        spinB_ActionTimes->setMaximum(99);

        horizontalLayout_3->addWidget(spinB_ActionTimes);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinB_ActionDuration = new QSpinBox(groupBox_2);
        spinB_ActionDuration->setObjectName(QString::fromUtf8("spinB_ActionDuration"));
        spinB_ActionDuration->setMinimum(5);
        spinB_ActionDuration->setMaximum(99);

        horizontalLayout_3->addWidget(spinB_ActionDuration);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        Btn_StartExercise = new QPushButton(ExerciseModule);
        Btn_StartExercise->setObjectName(QString::fromUtf8("Btn_StartExercise"));

        horizontalLayout_12->addWidget(Btn_StartExercise);

        progressBar = new QProgressBar(ExerciseModule);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_12->addWidget(progressBar);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_12);

        groupBox_3 = new QGroupBox(ExerciseModule);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tbView_Report = new QTableView(groupBox_3);
        tbView_Report->setObjectName(QString::fromUtf8("tbView_Report"));

        verticalLayout->addWidget(tbView_Report);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Btn_CreateReport = new QPushButton(groupBox_3);
        Btn_CreateReport->setObjectName(QString::fromUtf8("Btn_CreateReport"));

        horizontalLayout_6->addWidget(Btn_CreateReport);

        BtnExportReport = new QPushButton(groupBox_3);
        BtnExportReport->setObjectName(QString::fromUtf8("BtnExportReport"));

        horizontalLayout_6->addWidget(BtnExportReport);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 1);
        verticalLayout_2->setStretch(6, 1);
        verticalLayout_2->setStretch(7, 1);
        verticalLayout_2->setStretch(8, 6);

        horizontalLayout_13->addLayout(verticalLayout_2);


        retranslateUi(ExerciseModule);

        QMetaObject::connectSlotsByName(ExerciseModule);
    } // setupUi

    void retranslateUi(QDialog *ExerciseModule)
    {
        ExerciseModule->setWindowTitle(QApplication::translate("ExerciseModule", "ExerciseModule", 0, QApplication::UnicodeUTF8));
        BtnOpenPlugin->setText(QApplication::translate("ExerciseModule", "\346\211\223\345\274\200\345\210\206\347\261\273\345\231\250\346\217\222\344\273\266", 0, QApplication::UnicodeUTF8));
        BtnImportConfig->setText(QApplication::translate("ExerciseModule", "\345\257\274\345\205\245\350\256\255\347\273\203\351\205\215\347\275\256\346\226\207\344\273\266...", 0, QApplication::UnicodeUTF8));
        BtnImportData->setText(QApplication::translate("ExerciseModule", "\345\257\274\345\205\245\350\256\255\347\273\203\346\225\260\346\215\256\346\226\207\344\273\266...", 0, QApplication::UnicodeUTF8));
        BtnCreateClassifier->setText(QApplication::translate("ExerciseModule", "\347\224\237\346\210\220\345\210\206\347\261\273\345\231\250", 0, QApplication::UnicodeUTF8));
        BtnSaveClassifier->setText(QApplication::translate("ExerciseModule", "\344\277\235\345\255\230\345\210\206\347\261\273\345\231\250", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ExerciseModule", "\350\202\214\347\224\265\350\207\202\345\270\246\350\277\236\346\216\245\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExerciseModule", "\344\270\262\345\217\243\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        cbBox_Armband->clear();
        cbBox_Armband->insertItems(0, QStringList()
         << QApplication::translate("ExerciseModule", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ExerciseModule", "COM9", 0, QApplication::UnicodeUTF8)
        );
        Btn_Connect->setText(QApplication::translate("ExerciseModule", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExerciseModule", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ExerciseModule", "\346\265\213\350\257\225\347\233\270\345\205\263\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ExerciseModule", "\346\257\217\344\270\252\345\212\250\344\275\234\351\207\215\345\244\215\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ExerciseModule", "\346\234\200\345\244\247\345\260\235\350\257\225\346\227\266\351\227\264\357\274\232\347\247\222", 0, QApplication::UnicodeUTF8));
        Btn_StartExercise->setText(QApplication::translate("ExerciseModule", "\345\274\200\345\247\213\347\273\203\344\271\240", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ExerciseModule", "\346\234\254\346\254\241\347\273\203\344\271\240\346\212\245\345\221\212", 0, QApplication::UnicodeUTF8));
        Btn_CreateReport->setText(QApplication::translate("ExerciseModule", "\347\224\237\346\210\220\346\212\245\345\221\212", 0, QApplication::UnicodeUTF8));
        BtnExportReport->setText(QApplication::translate("ExerciseModule", "\345\257\274\345\207\272\346\212\245\345\221\212", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExerciseModule: public Ui_ExerciseModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISEMODULE_H
