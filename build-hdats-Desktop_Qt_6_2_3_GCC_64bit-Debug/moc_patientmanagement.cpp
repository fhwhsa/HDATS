/****************************************************************************
** Meta object code from reading C++ file 'patientmanagement.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HDATS/patientmanagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientmanagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientManagement_t {
    const uint offsetsAndSize[30];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PatientManagement_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PatientManagement_t qt_meta_stringdata_PatientManagement = {
    {
QT_MOC_LITERAL(0, 17), // "PatientManagement"
QT_MOC_LITERAL(18, 3), // "add"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 6), // "modify"
QT_MOC_LITERAL(30, 15), // "QSqlQueryModel*"
QT_MOC_LITERAL(46, 2), // "qm"
QT_MOC_LITERAL(49, 5), // "index"
QT_MOC_LITERAL(55, 20), // "do_currentRowChanged"
QT_MOC_LITERAL(76, 11), // "QModelIndex"
QT_MOC_LITERAL(88, 7), // "current"
QT_MOC_LITERAL(96, 8), // "previous"
QT_MOC_LITERAL(105, 10), // "do_btnFind"
QT_MOC_LITERAL(116, 9), // "do_btnAdd"
QT_MOC_LITERAL(126, 12), // "do_btnDelete"
QT_MOC_LITERAL(139, 12) // "do_btnModify"

    },
    "PatientManagement\0add\0\0modify\0"
    "QSqlQueryModel*\0qm\0index\0do_currentRowChanged\0"
    "QModelIndex\0current\0previous\0do_btnFind\0"
    "do_btnAdd\0do_btnDelete\0do_btnModify"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientManagement[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    2,   57,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   62,    2, 0x08,    5 /* Private */,
      11,    0,   67,    2, 0x08,    8 /* Private */,
      12,    0,   68,    2, 0x08,    9 /* Private */,
      13,    0,   69,    2, 0x08,   10 /* Private */,
      14,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PatientManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PatientManagement *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add(); break;
        case 1: _t->modify((*reinterpret_cast< QSqlQueryModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->do_currentRowChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: _t->do_btnFind(); break;
        case 4: _t->do_btnAdd(); break;
        case 5: _t->do_btnDelete(); break;
        case 6: _t->do_btnModify(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PatientManagement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientManagement::add)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PatientManagement::*)(QSqlQueryModel * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientManagement::modify)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PatientManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PatientManagement.offsetsAndSize,
    qt_meta_data_PatientManagement,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PatientManagement_t
, QtPrivate::TypeAndForceComplete<PatientManagement, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PatientManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientManagement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PatientManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PatientManagement::add()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PatientManagement::modify(QSqlQueryModel * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
