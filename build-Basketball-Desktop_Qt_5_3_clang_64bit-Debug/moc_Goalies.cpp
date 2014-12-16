/****************************************************************************
** Meta object code from reading C++ file 'Goalies.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/Goalies.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Goalies.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Goalies_t {
    QByteArrayData data[11];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Goalies_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Goalies_t qt_meta_stringdata_Goalies = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 6),
QT_MOC_LITERAL(4, 30, 13),
QT_MOC_LITERAL(5, 44, 13),
QT_MOC_LITERAL(6, 58, 13),
QT_MOC_LITERAL(7, 72, 9),
QT_MOC_LITERAL(8, 82, 9),
QT_MOC_LITERAL(9, 92, 9),
QT_MOC_LITERAL(10, 102, 9)
    },
    "Goalies\0requestHomeLt\0\0player\0"
    "requestAwayLt\0requestHomeSb\0requestAwaySb\0"
    "getHomeLt\0getAwayLt\0getHomeSb\0getAwaySb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Goalies[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Goalies::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Goalies *_t = static_cast<Goalies *>(_o);
        switch (_id) {
        case 0: _t->requestHomeLt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->requestAwayLt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->requestHomeSb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->requestAwaySb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getHomeLt(); break;
        case 5: _t->getAwayLt(); break;
        case 6: _t->getHomeSb(); break;
        case 7: _t->getAwaySb(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Goalies::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goalies::requestHomeLt)) {
                *result = 0;
            }
        }
        {
            typedef void (Goalies::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goalies::requestAwayLt)) {
                *result = 1;
            }
        }
        {
            typedef void (Goalies::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goalies::requestHomeSb)) {
                *result = 2;
            }
        }
        {
            typedef void (Goalies::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goalies::requestAwaySb)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Goalies::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Goalies.data,
      qt_meta_data_Goalies,  qt_static_metacall, 0, 0}
};


const QMetaObject *Goalies::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Goalies::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Goalies.stringdata))
        return static_cast<void*>(const_cast< Goalies*>(this));
    return QWidget::qt_metacast(_clname);
}

int Goalies::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Goalies::requestHomeLt(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Goalies::requestAwayLt(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Goalies::requestHomeSb(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Goalies::requestAwaySb(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
