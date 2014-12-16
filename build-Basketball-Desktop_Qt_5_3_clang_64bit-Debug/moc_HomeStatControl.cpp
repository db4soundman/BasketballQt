/****************************************************************************
** Meta object code from reading C++ file 'HomeStatControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/HomeStatControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HomeStatControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HomeStatControl_t {
    QByteArrayData data[7];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeStatControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeStatControl_t qt_meta_stringdata_HomeStatControl = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 15),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 5),
QT_MOC_LITERAL(4, 39, 15),
QT_MOC_LITERAL(5, 55, 13),
QT_MOC_LITERAL(6, 69, 13)
    },
    "HomeStatControl\0requestSeasonLt\0\0index\0"
    "requestSeasonSb\0requestGameSb\0"
    "requestGameLt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeStatControl[] = {

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
       1,    0,   66,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       4,    0,   69,    2, 0x08 /* Private */,

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

void HomeStatControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HomeStatControl *_t = static_cast<HomeStatControl *>(_o);
        switch (_id) {
        case 0: _t->requestSeasonLt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->requestSeasonSb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->requestGameSb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->requestGameLt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->requestSeasonLt(); break;
        case 5: _t->requestGameLt(); break;
        case 6: _t->requestGameSb(); break;
        case 7: _t->requestSeasonSb(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HomeStatControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HomeStatControl::requestSeasonLt)) {
                *result = 0;
            }
        }
        {
            typedef void (HomeStatControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HomeStatControl::requestSeasonSb)) {
                *result = 1;
            }
        }
        {
            typedef void (HomeStatControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HomeStatControl::requestGameSb)) {
                *result = 2;
            }
        }
        {
            typedef void (HomeStatControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HomeStatControl::requestGameLt)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject HomeStatControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomeStatControl.data,
      qt_meta_data_HomeStatControl,  qt_static_metacall, 0, 0}
};


const QMetaObject *HomeStatControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeStatControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomeStatControl.stringdata))
        return static_cast<void*>(const_cast< HomeStatControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int HomeStatControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HomeStatControl::requestSeasonLt(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HomeStatControl::requestSeasonSb(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HomeStatControl::requestGameSb(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HomeStatControl::requestGameLt(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
