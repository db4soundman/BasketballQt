/****************************************************************************
** Meta object code from reading C++ file 'Scoreboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Scoreboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scoreboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Scoreboard_t {
    QByteArrayData data[24];
    char stringdata[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scoreboard_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scoreboard_t qt_meta_stringdata_Scoreboard = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 6),
QT_MOC_LITERAL(4, 33, 5),
QT_MOC_LITERAL(5, 39, 21),
QT_MOC_LITERAL(6, 61, 3),
QT_MOC_LITERAL(7, 65, 6),
QT_MOC_LITERAL(8, 72, 5),
QT_MOC_LITERAL(9, 78, 11),
QT_MOC_LITERAL(10, 90, 15),
QT_MOC_LITERAL(11, 106, 5),
QT_MOC_LITERAL(12, 112, 15),
QT_MOC_LITERAL(13, 128, 12),
QT_MOC_LITERAL(14, 141, 2),
QT_MOC_LITERAL(15, 144, 16),
QT_MOC_LITERAL(16, 161, 4),
QT_MOC_LITERAL(17, 166, 15),
QT_MOC_LITERAL(18, 182, 14),
QT_MOC_LITERAL(19, 197, 9),
QT_MOC_LITERAL(20, 207, 11),
QT_MOC_LITERAL(21, 219, 12),
QT_MOC_LITERAL(22, 232, 12),
QT_MOC_LITERAL(23, 245, 14)
    },
    "Scoreboard\0togglePenalty\0\0showPd\0final\0"
    "preparePowerplayClock\0pos\0Clock*\0clock\0"
    "description\0updateHomeScore\0score\0"
    "updateAwayScore\0updatePeriod\0pd\0"
    "changeTopBarText\0text\0toggleShowBoard\0"
    "togglePpClocks\0hideBoard\0updateClock\0"
    "intermission\0displayClock\0displaySponsor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scoreboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    3,  102,    2, 0x0a /* Public */,
       5,    2,  109,    2, 0x2a /* Public | MethodCloned */,
       5,    1,  114,    2, 0x2a /* Public | MethodCloned */,
      10,    1,  117,    2, 0x0a /* Public */,
      12,    1,  120,    2, 0x0a /* Public */,
      13,    1,  123,    2, 0x0a /* Public */,
      15,    1,  126,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,
      22,    0,  134,    2, 0x0a /* Public */,
      23,    0,  135,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7, QMetaType::QString,    6,    8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Scoreboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scoreboard *_t = static_cast<Scoreboard *>(_o);
        switch (_id) {
        case 0: _t->togglePenalty(); break;
        case 1: _t->showPd(); break;
        case 2: _t->final(); break;
        case 3: _t->preparePowerplayClock((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Clock*(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->preparePowerplayClock((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Clock*(*)>(_a[2]))); break;
        case 5: _t->preparePowerplayClock((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateHomeScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateAwayScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updatePeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeTopBarText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->toggleShowBoard(); break;
        case 11: _t->togglePpClocks(); break;
        case 12: _t->hideBoard(); break;
        case 13: _t->updateClock(); break;
        case 14: _t->intermission(); break;
        case 15: _t->displayClock(); break;
        case 16: _t->displaySponsor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Clock* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Clock* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Scoreboard::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scoreboard.data,
      qt_meta_data_Scoreboard,  qt_static_metacall, 0, 0}
};


const QMetaObject *Scoreboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scoreboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scoreboard.stringdata))
        return static_cast<void*>(const_cast< Scoreboard*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Scoreboard*>(this));
    return QObject::qt_metacast(_clname);
}

int Scoreboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
