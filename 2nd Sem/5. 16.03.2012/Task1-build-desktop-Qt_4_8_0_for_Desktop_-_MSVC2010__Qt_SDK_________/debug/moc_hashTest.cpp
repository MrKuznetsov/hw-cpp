/****************************************************************************
** Meta object code from reading C++ file 'hashTest.h'
**
** Created: Wed 23. May 23:45:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../hash/Task1/hashTest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hashTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HashTest[] = {

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
      10,    9,    9,    9, 0x08,
      17,    9,    9,    9, 0x08,
      27,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HashTest[] = {
    "HashTest\0\0init()\0cleanup()\0testAdd()\0"
    "testRemove()\0"
};

void HashTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HashTest *_t = static_cast<HashTest *>(_o);
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->cleanup(); break;
        case 2: _t->testAdd(); break;
        case 3: _t->testRemove(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HashTest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HashTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HashTest,
      qt_meta_data_HashTest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HashTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HashTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HashTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HashTest))
        return static_cast<void*>(const_cast< HashTest*>(this));
    return QObject::qt_metacast(_clname);
}

int HashTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
