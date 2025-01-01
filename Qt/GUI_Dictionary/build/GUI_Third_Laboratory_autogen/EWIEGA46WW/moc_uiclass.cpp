/****************************************************************************
** Meta object code from reading C++ file 'uiclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../uiclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIClass_t {
    QByteArrayData data[22];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIClass_t qt_meta_stringdata_UIClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "UIClass"
QT_MOC_LITERAL(1, 8, 19), // "slotOpenFirstWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 20), // "slotOpenSecondWindow"
QT_MOC_LITERAL(4, 50, 27), // "slotAutomaticallyCreateData"
QT_MOC_LITERAL(5, 78, 32), // "slotAutomaticallyCreateDataFinal"
QT_MOC_LITERAL(6, 111, 9), // "strNumber"
QT_MOC_LITERAL(7, 121, 19), // "slotWriteDataToFile"
QT_MOC_LITERAL(8, 141, 24), // "slotWriteDataToFileFinal"
QT_MOC_LITERAL(9, 166, 7), // "strName"
QT_MOC_LITERAL(10, 174, 14), // "slotChooseFile"
QT_MOC_LITERAL(11, 189, 19), // "slotPrintDictionary"
QT_MOC_LITERAL(12, 209, 12), // "slotOpenFile"
QT_MOC_LITERAL(13, 222, 11), // "QModelIndex"
QT_MOC_LITERAL(14, 234, 7), // "slotAdd"
QT_MOC_LITERAL(15, 242, 7), // "slotGet"
QT_MOC_LITERAL(16, 250, 13), // "slotGetSecond"
QT_MOC_LITERAL(17, 264, 3), // "key"
QT_MOC_LITERAL(18, 268, 12), // "slotGetFinal"
QT_MOC_LITERAL(19, 281, 8), // "newValue"
QT_MOC_LITERAL(20, 290, 10), // "slotRemove"
QT_MOC_LITERAL(21, 301, 17) // "slotPrintGraphics"

    },
    "UIClass\0slotOpenFirstWindow\0\0"
    "slotOpenSecondWindow\0slotAutomaticallyCreateData\0"
    "slotAutomaticallyCreateDataFinal\0"
    "strNumber\0slotWriteDataToFile\0"
    "slotWriteDataToFileFinal\0strName\0"
    "slotChooseFile\0slotPrintDictionary\0"
    "slotOpenFile\0QModelIndex\0slotAdd\0"
    "slotGet\0slotGetSecond\0key\0slotGetFinal\0"
    "newValue\0slotRemove\0slotPrintGraphics"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      11,    0,  102,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    0,  114,    2, 0x08 /* Private */,
      21,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UIClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UIClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotOpenFirstWindow(); break;
        case 1: _t->slotOpenSecondWindow(); break;
        case 2: _t->slotAutomaticallyCreateData(); break;
        case 3: _t->slotAutomaticallyCreateDataFinal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotWriteDataToFile(); break;
        case 5: _t->slotWriteDataToFileFinal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotChooseFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->slotPrintDictionary(); break;
        case 8: _t->slotOpenFile((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->slotAdd(); break;
        case 10: _t->slotGet(); break;
        case 11: _t->slotGetSecond((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slotGetFinal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slotRemove(); break;
        case 14: _t->slotPrintGraphics(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UIClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UIClass.data,
    qt_meta_data_UIClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UIClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UIClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UIClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
