/****************************************************************************
** Meta object code from reading C++ file 'LowerThirdCreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LowerThirdCreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LowerThirdCreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LowerThirdCreator_t {
    QByteArrayData data[12];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LowerThirdCreator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LowerThirdCreator_t qt_meta_stringdata_LowerThirdCreator = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 12),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 4),
QT_MOC_LITERAL(4, 37, 6),
QT_MOC_LITERAL(5, 44, 4),
QT_MOC_LITERAL(6, 49, 14),
QT_MOC_LITERAL(7, 64, 6),
QT_MOC_LITERAL(8, 71, 4),
QT_MOC_LITERAL(9, 76, 8),
QT_MOC_LITERAL(10, 85, 11),
QT_MOC_LITERAL(11, 97, 8)
    },
    "LowerThirdCreator\0makeCustomLt\0\0name\0"
    "number\0year\0QList<QString>\0header\0"
    "text\0homeTeam\0clearFields\0submitLt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LowerThirdCreator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   42,    2, 0x08 /* Private */,
      11,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6, 0x80000000 | 6, QMetaType::Bool,    3,    4,    5,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LowerThirdCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LowerThirdCreator *_t = static_cast<LowerThirdCreator *>(_o);
        switch (_id) {
        case 0: _t->makeCustomLt((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4])),(*reinterpret_cast< QList<QString>(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 1: _t->clearFields(); break;
        case 2: _t->submitLt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LowerThirdCreator::*_t)(QString , QString , QString , QList<QString> , QList<QString> , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LowerThirdCreator::makeCustomLt)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LowerThirdCreator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LowerThirdCreator.data,
      qt_meta_data_LowerThirdCreator,  qt_static_metacall, 0, 0}
};


const QMetaObject *LowerThirdCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LowerThirdCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LowerThirdCreator.stringdata))
        return static_cast<void*>(const_cast< LowerThirdCreator*>(this));
    return QWidget::qt_metacast(_clname);
}

int LowerThirdCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LowerThirdCreator::makeCustomLt(QString _t1, QString _t2, QString _t3, QList<QString> _t4, QList<QString> _t5, bool _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
