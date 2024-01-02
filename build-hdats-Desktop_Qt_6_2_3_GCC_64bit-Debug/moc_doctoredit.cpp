/****************************************************************************
** Meta object code from reading C++ file 'doctoredit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HDATS/doctoredit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctoredit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorEdit_t {
    const uint offsetsAndSize[12];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DoctorEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DoctorEdit_t qt_meta_stringdata_DoctorEdit = {
    {
QT_MOC_LITERAL(0, 10), // "DoctorEdit"
QT_MOC_LITERAL(11, 14), // "clickBtnCancel"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 12), // "clickBtnSave"
QT_MOC_LITERAL(40, 10), // "do_btnSave"
QT_MOC_LITERAL(51, 12) // "do_btnCancel"

    },
    "DoctorEdit\0clickBtnCancel\0\0clickBtnSave\0"
    "do_btnSave\0do_btnCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    0,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DoctorEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoctorEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clickBtnCancel(); break;
        case 1: _t->clickBtnSave(); break;
        case 2: _t->do_btnSave(); break;
        case 3: _t->do_btnCancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoctorEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorEdit::clickBtnCancel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DoctorEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorEdit::clickBtnSave)) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject DoctorEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DoctorEdit.offsetsAndSize,
    qt_meta_data_DoctorEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DoctorEdit_t
, QtPrivate::TypeAndForceComplete<DoctorEdit, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DoctorEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DoctorEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DoctorEdit::clickBtnCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DoctorEdit::clickBtnSave()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
