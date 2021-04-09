/****************************************************************************
** Meta object code from reading C++ file 'dsdesign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DSDesign/dsdesign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dsdesign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DSDesign_t {
    QByteArrayData data[10];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DSDesign_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DSDesign_t qt_meta_stringdata_DSDesign = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DSDesign"
QT_MOC_LITERAL(1, 9, 23), // "on_btn_classnum_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "on_btn_over_clicked"
QT_MOC_LITERAL(4, 54, 23), // "on_btn_toltimes_clicked"
QT_MOC_LITERAL(5, 78, 21), // "on_btn_output_clicked"
QT_MOC_LITERAL(6, 100, 21), // "on_btn_delete_clicked"
QT_MOC_LITERAL(7, 122, 19), // "on_btn_sort_clicked"
QT_MOC_LITERAL(8, 142, 21), // "on_btn_search_clicked"
QT_MOC_LITERAL(9, 164, 21) // "on_btn_change_clicked"

    },
    "DSDesign\0on_btn_classnum_clicked\0\0"
    "on_btn_over_clicked\0on_btn_toltimes_clicked\0"
    "on_btn_output_clicked\0on_btn_delete_clicked\0"
    "on_btn_sort_clicked\0on_btn_search_clicked\0"
    "on_btn_change_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DSDesign[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DSDesign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DSDesign *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_classnum_clicked(); break;
        case 1: _t->on_btn_over_clicked(); break;
        case 2: _t->on_btn_toltimes_clicked(); break;
        case 3: _t->on_btn_output_clicked(); break;
        case 4: _t->on_btn_delete_clicked(); break;
        case 5: _t->on_btn_sort_clicked(); break;
        case 6: _t->on_btn_search_clicked(); break;
        case 7: _t->on_btn_change_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DSDesign::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DSDesign.data,
    qt_meta_data_DSDesign,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DSDesign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DSDesign::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DSDesign.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DSDesign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
