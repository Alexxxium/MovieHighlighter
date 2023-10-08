/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../controller/include/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mv__ctrl__Controller_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mv__ctrl__Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mv__ctrl__Controller_t qt_meta_stringdata_mv__ctrl__Controller = {
    {
QT_MOC_LITERAL(0, 0, 20), // "mv::ctrl::Controller"
QT_MOC_LITERAL(1, 21, 8), // "catchLog"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "std::string"
QT_MOC_LITERAL(4, 43, 3), // "log"
QT_MOC_LITERAL(5, 47, 11), // "createMovie"
QT_MOC_LITERAL(6, 59, 5), // "frize"
QT_MOC_LITERAL(7, 65, 3) // "val"

    },
    "mv::ctrl::Controller\0catchLog\0\0"
    "std::string\0log\0createMovie\0frize\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mv__ctrl__Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

       0        // eod
};

void mv::ctrl::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->catchLog((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->createMovie(); break;
        case 2: _t->frize((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->frize(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mv::ctrl::Controller::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_mv__ctrl__Controller.data,
    qt_meta_data_mv__ctrl__Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mv::ctrl::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mv::ctrl::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mv__ctrl__Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int mv::ctrl::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
