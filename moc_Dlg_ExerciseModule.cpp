/****************************************************************************
** Meta object code from reading C++ file 'Dlg_ExerciseModule.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Dlg_ExerciseModule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Dlg_ExerciseModule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dlg_ExerciseModule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      47,   19,   19,   19, 0x0a,
      76,   19,   19,   19, 0x0a,
     103,   19,   19,   19, 0x0a,
     136,   19,   19,   19, 0x0a,
     167,   19,   19,   19, 0x0a,
     192,   19,   19,   19, 0x0a,
     223,   19,   19,   19, 0x0a,
     253,   19,   19,   19, 0x0a,
     282,   19,   19,   19, 0x0a,
     317,   19,   19,   19, 0x0a,
     339,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dlg_ExerciseModule[] = {
    "Dlg_ExerciseModule\0\0on_BtnOpenPlugin_clicked()\0"
    "on_BtnImportConfig_clicked()\0"
    "on_BtnImportData_clicked()\0"
    "on_BtnCreateClassifier_clicked()\0"
    "on_BtnSaveClassifier_clicked()\0"
    "on_Btn_Connect_clicked()\0"
    "on_Btn_StartExercise_clicked()\0"
    "on_Btn_CreateReport_clicked()\0"
    "on_BtnExportReport_clicked()\0"
    "on_Btn_ApplyFingerReturn_clicked()\0"
    "on_Btn_test_clicked()\0_qTimer_timeout()\0"
};

void Dlg_ExerciseModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dlg_ExerciseModule *_t = static_cast<Dlg_ExerciseModule *>(_o);
        switch (_id) {
        case 0: _t->on_BtnOpenPlugin_clicked(); break;
        case 1: _t->on_BtnImportConfig_clicked(); break;
        case 2: _t->on_BtnImportData_clicked(); break;
        case 3: _t->on_BtnCreateClassifier_clicked(); break;
        case 4: _t->on_BtnSaveClassifier_clicked(); break;
        case 5: _t->on_Btn_Connect_clicked(); break;
        case 6: _t->on_Btn_StartExercise_clicked(); break;
        case 7: _t->on_Btn_CreateReport_clicked(); break;
        case 8: _t->on_BtnExportReport_clicked(); break;
        case 9: _t->on_Btn_ApplyFingerReturn_clicked(); break;
        case 10: _t->on_Btn_test_clicked(); break;
        case 11: _t->_qTimer_timeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Dlg_ExerciseModule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dlg_ExerciseModule::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dlg_ExerciseModule,
      qt_meta_data_Dlg_ExerciseModule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dlg_ExerciseModule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dlg_ExerciseModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dlg_ExerciseModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dlg_ExerciseModule))
        return static_cast<void*>(const_cast< Dlg_ExerciseModule*>(this));
    if (!strcmp(_clname, "Ui_ExerciseModule"))
        return static_cast< Ui_ExerciseModule*>(const_cast< Dlg_ExerciseModule*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dlg_ExerciseModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
