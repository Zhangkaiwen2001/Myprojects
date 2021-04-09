/****************************************************************************
** Meta object code from reading C++ file 'secretary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../secretary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secretary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_secretary_t {
    QByteArrayData data[16];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_secretary_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_secretary_t qt_meta_stringdata_secretary = {
    {
QT_MOC_LITERAL(0, 0, 9), // "secretary"
QT_MOC_LITERAL(1, 10, 16), // "updataTTimetable"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "updataSTimetable"
QT_MOC_LITERAL(4, 45, 16), // "updataRTimetable"
QT_MOC_LITERAL(5, 62, 12), // "TAddBtnEvent"
QT_MOC_LITERAL(6, 75, 12), // "CAddBtnEvent"
QT_MOC_LITERAL(7, 88, 12), // "TDelBtnEvent"
QT_MOC_LITERAL(8, 101, 12), // "CDelBtnEvent"
QT_MOC_LITERAL(9, 114, 11), // "TClearEvent"
QT_MOC_LITERAL(10, 126, 11), // "CClearEvent"
QT_MOC_LITERAL(11, 138, 10), // "startEvent"
QT_MOC_LITERAL(12, 149, 14), // "updataClassBox"
QT_MOC_LITERAL(13, 164, 9), // "slot_menu"
QT_MOC_LITERAL(14, 174, 15), // "slot_changetime"
QT_MOC_LITERAL(15, 190, 15) // "slot_changeroom"

    },
    "secretary\0updataTTimetable\0\0"
    "updataSTimetable\0updataRTimetable\0"
    "TAddBtnEvent\0CAddBtnEvent\0TDelBtnEvent\0"
    "CDelBtnEvent\0TClearEvent\0CClearEvent\0"
    "startEvent\0updataClassBox\0slot_menu\0"
    "slot_changetime\0slot_changeroom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_secretary[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       3,    1,   87,    2, 0x08 /* Private */,
       4,    1,   90,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      13,    1,  103,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void secretary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        secretary *_t = static_cast<secretary *>(_o);
        switch (_id) {
        case 0: _t->updataTTimetable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updataSTimetable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updataRTimetable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->TAddBtnEvent(); break;
        case 4: _t->CAddBtnEvent(); break;
        case 5: _t->TDelBtnEvent(); break;
        case 6: _t->CDelBtnEvent(); break;
        case 7: _t->TClearEvent(); break;
        case 8: _t->CClearEvent(); break;
        case 9: _t->startEvent(); break;
        case 10: _t->updataClassBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slot_menu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->slot_changetime(); break;
        case 13: _t->slot_changeroom(); break;
        default: ;
        }
    }
}

const QMetaObject secretary::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_secretary.data,
      qt_meta_data_secretary,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *secretary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *secretary::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_secretary.stringdata))
        return static_cast<void*>(const_cast< secretary*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int secretary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
