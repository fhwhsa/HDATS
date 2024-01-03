QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = hdats

SOURCES += \
    departmentmanagement.cpp \
    diagnosticrecords.cpp \
    doctoredit.cpp \
    doctormanagement.cpp \
    drugedit.cpp \
    drugmanagement.cpp \
    idatabase.cpp \
    login.cpp \
    main.cpp \
    masterview.cpp \
    patientedit.cpp \
    patientmanagement.cpp \
    welcome.cpp

HEADERS += \
    departmentmanagement.h \
    diagnosticrecords.h \
    doctoredit.h \
    doctormanagement.h \
    drugedit.h \
    drugmanagement.h \
    idatabase.h \
    login.h \
    masterview.h \
    patientedit.h \
    patientmanagement.h \
    welcome.h

FORMS += \
    departmentmanagement.ui \
    diagnosticrecords.ui \
    doctoredit.ui \
    doctormanagement.ui \
    drugedit.ui \
    drugmanagement.ui \
    login.ui \
    masterview.ui \
    patientedit.ui \
    patientmanagement.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
