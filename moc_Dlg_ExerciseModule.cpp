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
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      40,   19,   19,   19, 0x0a,
      63,   19,   19,   19, 0x0a,
      84,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dlg_ExerciseModule[] = {
    "Dlg_ExerciseModule\0\0on_Btn_Do_clicked()\0"
    "on_Btn_Clear_clicked()\0on_Btn_Set_clicked()\0"
    "_qTimer_timeout()\0"
};

void Dlg_ExerciseModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dlg_ExerciseModule *_t = static_cast<Dlg_ExerciseModule *>(_o);
        switch (_id) {
        case 0: _t->on_Btn_Do_clicked(); break;
        case 1: _t->on_Btn_Clear_clicked(); break;
        case 2: _t->on_Btn_Set_clicked(); break;
        case 3: _t->_qTimer_timeout(); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
