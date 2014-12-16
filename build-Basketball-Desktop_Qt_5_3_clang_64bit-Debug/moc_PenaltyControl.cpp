/****************************************************************************
** Meta object code from reading C++ file 'PenaltyControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/PenaltyControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PenaltyControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PenaltyControl_t {
    QByteArrayData data[12];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PenaltyControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PenaltyControl_t qt_meta_stringdata_PenaltyControl = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 11),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 6),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 13),
QT_MOC_LITERAL(6, 61, 7),
QT_MOC_LITERAL(7, 69, 8),
QT_MOC_LITERAL(8, 78, 8),
QT_MOC_LITERAL(9, 87, 7),
QT_MOC_LITERAL(10, 95, 8),
QT_MOC_LITERAL(11, 104, 8)
    },
    "PenaltyControl\0awayPenalty\0\0length\0"
    "homePenalty\0editPenalties\0awayTwo\0"
    "awayFour\0awayFive\0homeTwo\0homeFour\0"
    "homeFive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PenaltyControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PenaltyControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PenaltyControl *_t = static_cast<PenaltyControl *>(_o);
        switch (_id) {
        case 0: _t->awayPenalty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->homePenalty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->editPenalties(); break;
        case 3: _t->awayTwo(); break;
        case 4: _t->awayFour(); break;
        case 5: _t->awayFive(); break;
        case 6: _t->homeTwo(); break;
        case 7: _t->homeFour(); break;
        case 8: _t->homeFive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PenaltyControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PenaltyControl::awayPenalty)) {
                *result = 0;
            }
        }
        {
            typedef void (PenaltyControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PenaltyControl::homePenalty)) {
                *result = 1;
            }
        }
        {
            typedef void (PenaltyControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PenaltyControl::editPenalties)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject PenaltyControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PenaltyControl.data,
      qt_meta_data_PenaltyControl,  qt_static_metacall, 0, 0}
};


const QMetaObject *PenaltyControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PenaltyControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PenaltyControl.stringdata))
        return static_cast<void*>(const_cast< PenaltyControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int PenaltyControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void PenaltyControl::awayPenalty(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PenaltyControl::homePenalty(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PenaltyControl::editPenalties()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
