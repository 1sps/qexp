/****************************************************************************
** Meta object code from reading C++ file 'mymodel.h'
**
** Created: Thu Jan 19 19:54:04 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mymodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      26,   19,    8,    8, 0x08,
      45,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,
      70,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyModel[] = {
    "MyModel\0\0addData()\0newExp\0pushData(expData*)\0"
    "writeToFile()\0sortData()\0searchData()\0"
};

void MyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyModel *_t = static_cast<MyModel *>(_o);
        switch (_id) {
        case 0: _t->addData(); break;
        case 1: _t->pushData((*reinterpret_cast< expData*(*)>(_a[1]))); break;
        case 2: _t->writeToFile(); break;
        case 3: _t->sortData(); break;
        case 4: _t->searchData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_MyModel,
      qt_meta_data_MyModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyModel))
        return static_cast<void*>(const_cast< MyModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int MyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
