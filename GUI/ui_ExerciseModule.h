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
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ExerciseModule
{
public:
    QSpinBox *spinBox;
    QPushButton *Btn_Do;
    QPushButton *Btn_Clear;
    QSpinBox *spinBoxFingerReturn;
    QPushButton *Btn_Set;

    void setupUi(QDialog *ExerciseModule)
    {
        if (ExerciseModule->objectName().isEmpty())
            ExerciseModule->setObjectName(QString::fromUtf8("ExerciseModule"));
        ExerciseModule->resize(400, 300);
        spinBox = new QSpinBox(ExerciseModule);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(40, 80, 101, 22));
        spinBox->setMaximum(999999999);
        Btn_Do = new QPushButton(ExerciseModule);
        Btn_Do->setObjectName(QString::fromUtf8("Btn_Do"));
        Btn_Do->setGeometry(QRect(170, 80, 75, 23));
        Btn_Clear = new QPushButton(ExerciseModule);
        Btn_Clear->setObjectName(QString::fromUtf8("Btn_Clear"));
        Btn_Clear->setGeometry(QRect(170, 120, 75, 23));
        spinBoxFingerReturn = new QSpinBox(ExerciseModule);
        spinBoxFingerReturn->setObjectName(QString::fromUtf8("spinBoxFingerReturn"));
        spinBoxFingerReturn->setGeometry(QRect(50, 180, 101, 21));
        spinBoxFingerReturn->setMaximum(999999999);
        Btn_Set = new QPushButton(ExerciseModule);
        Btn_Set->setObjectName(QString::fromUtf8("Btn_Set"));
        Btn_Set->setGeometry(QRect(170, 180, 75, 23));

        retranslateUi(ExerciseModule);

        QMetaObject::connectSlotsByName(ExerciseModule);
    } // setupUi

    void retranslateUi(QDialog *ExerciseModule)
    {
        ExerciseModule->setWindowTitle(QApplication::translate("ExerciseModule", "ExerciseModule", 0, QApplication::UnicodeUTF8));
        Btn_Do->setText(QApplication::translate("ExerciseModule", "Do", 0, QApplication::UnicodeUTF8));
        Btn_Clear->setText(QApplication::translate("ExerciseModule", "Clear", 0, QApplication::UnicodeUTF8));
        Btn_Set->setText(QApplication::translate("ExerciseModule", "Set", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExerciseModule: public Ui_ExerciseModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISEMODULE_H
