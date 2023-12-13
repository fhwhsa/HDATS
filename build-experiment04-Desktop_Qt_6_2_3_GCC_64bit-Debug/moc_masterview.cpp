/****************************************************************************
** Meta object code from reading C++ file 'masterview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../experiment04/masterview.h"
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
    const uint offsetsAndSize[30];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MasterView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MasterView_t qt_meta_stringdata_MasterView = {
    {
QT_MOC_LITERAL(0, 10), // "MasterView"
QT_MOC_LITERAL(11, 13), // "goToLoginView"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 15), // "goToWelcomeView"
QT_MOC_LITERAL(42, 19), // "goToDepartmentMView"
QT_MOC_LITERAL(62, 15), // "goToDoctorMView"
QT_MOC_LITERAL(78, 16), // "goToPatientMView"
QT_MOC_LITERAL(95, 25), // "goToPatientEditViewForAdd"
QT_MOC_LITERAL(121, 15), // "QSqlTableModel*"
QT_MOC_LITERAL(137, 2), // "tm"
QT_MOC_LITERAL(140, 28), // "goToPatientEditViewForModify"
QT_MOC_LITERAL(169, 5), // "index"
QT_MOC_LITERAL(175, 10), // "pageChange"
QT_MOC_LITERAL(186, 4), // "back"
QT_MOC_LITERAL(191, 8) // "loginout"

    },
    "MasterView\0goToLoginView\0\0goToWelcomeView\0"
    "goToDepartmentMView\0goToDoctorMView\0"
    "goToPatientMView\0goToPatientEditViewForAdd\0"
    "QSqlTableModel*\0tm\0goToPatientEditViewForModify\0"
    "index\0pageChange\0back\0loginout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MasterView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    1,   79,    2, 0x08,    6 /* Private */,
      10,    2,   82,    2, 0x08,    8 /* Private */,
      12,    1,   87,    2, 0x08,   11 /* Private */,
      13,    0,   90,    2, 0x08,   13 /* Private */,
      14,    0,   91,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   11,
    QMetaType::Void, QMetaType::Int,   11,
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
        case 1: _t->goToWelcomeView(); break;
        case 2: _t->goToDepartmentMView(); break;
        case 3: _t->goToDoctorMView(); break;
        case 4: _t->goToPatientMView(); break;
        case 5: _t->goToPatientEditViewForAdd((*reinterpret_cast< QSqlTableModel*(*)>(_a[1]))); break;
        case 6: _t->goToPatientEditViewForModify((*reinterpret_cast< QSqlTableModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->pageChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->back(); break;
        case 9: _t->loginout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlTableModel* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlTableModel* >(); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlTableModel *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSqlTableModel *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
