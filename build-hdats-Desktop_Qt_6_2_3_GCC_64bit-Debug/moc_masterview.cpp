/****************************************************************************
** Meta object code from reading C++ file 'masterview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HDATS/masterview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'masterview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MasterView_t {
    const uint offsetsAndSize[40];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MasterView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MasterView_t qt_meta_stringdata_MasterView = {
    {
QT_MOC_LITERAL(0, 10), // "MasterView"
QT_MOC_LITERAL(11, 13), // "goToLoginView"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 15), // "goToWelcomeView"
QT_MOC_LITERAL(42, 6), // "pLevel"
QT_MOC_LITERAL(49, 21), // "goToDiagnosticRecords"
QT_MOC_LITERAL(71, 13), // "goToDrugMView"
QT_MOC_LITERAL(85, 15), // "goToDepartmentM"
QT_MOC_LITERAL(101, 15), // "goToDoctorMView"
QT_MOC_LITERAL(117, 24), // "goToDoctorEditViewForAdd"
QT_MOC_LITERAL(142, 27), // "goToDoctorEditViewForModify"
QT_MOC_LITERAL(170, 15), // "QSqlQueryModel*"
QT_MOC_LITERAL(186, 2), // "qm"
QT_MOC_LITERAL(189, 5), // "index"
QT_MOC_LITERAL(195, 16), // "goToPatientMView"
QT_MOC_LITERAL(212, 25), // "goToPatientEditViewForAdd"
QT_MOC_LITERAL(238, 28), // "goToPatientEditViewForModify"
QT_MOC_LITERAL(267, 10), // "pageChange"
QT_MOC_LITERAL(278, 4), // "back"
QT_MOC_LITERAL(283, 8) // "loginout"

    },
    "MasterView\0goToLoginView\0\0goToWelcomeView\0"
    "pLevel\0goToDiagnosticRecords\0goToDrugMView\0"
    "goToDepartmentM\0goToDoctorMView\0"
    "goToDoctorEditViewForAdd\0"
    "goToDoctorEditViewForModify\0QSqlQueryModel*\0"
    "qm\0index\0goToPatientMView\0"
    "goToPatientEditViewForAdd\0"
    "goToPatientEditViewForModify\0pageChange\0"
    "back\0loginout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MasterView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    1,   99,    2, 0x08,    2 /* Private */,
       5,    0,  102,    2, 0x08,    4 /* Private */,
       6,    0,  103,    2, 0x08,    5 /* Private */,
       7,    0,  104,    2, 0x08,    6 /* Private */,
       8,    0,  105,    2, 0x08,    7 /* Private */,
       9,    0,  106,    2, 0x08,    8 /* Private */,
      10,    2,  107,    2, 0x08,    9 /* Private */,
      14,    0,  112,    2, 0x08,   12 /* Private */,
      15,    0,  113,    2, 0x08,   13 /* Private */,
      16,    2,  114,    2, 0x08,   14 /* Private */,
      17,    1,  119,    2, 0x08,   17 /* Private */,
      18,    0,  122,    2, 0x08,   19 /* Private */,
      19,    0,  123,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MasterView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MasterView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToLoginView(); break;
        case 1: _t->goToWelcomeView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->goToDiagnosticRecords(); break;
        case 3: _t->goToDrugMView(); break;
        case 4: _t->goToDepartmentM(); break;
        case 5: _t->goToDoctorMView(); break;
        case 6: _t->goToDoctorEditViewForAdd(); break;
        case 7: _t->goToDoctorEditViewForModify((*reinterpret_cast< QSqlQueryModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->goToPatientMView(); break;
        case 9: _t->goToPatientEditViewForAdd(); break;
        case 10: _t->goToPatientEditViewForModify((*reinterpret_cast< QSqlQueryModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->pageChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->back(); break;
        case 13: _t->loginout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MasterView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MasterView.offsetsAndSize,
    qt_meta_data_MasterView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MasterView_t
, QtPrivate::TypeAndForceComplete<MasterView, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MasterView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MasterView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MasterView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MasterView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
