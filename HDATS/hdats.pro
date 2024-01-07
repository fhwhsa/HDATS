QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = hdats

SOURCES += \
    currloginuserinfo.cpp \
    diagnosticrecord.cpp \
    diagnosticrecordedit.cpp \
    doctoredit.cpp \
    doctormanagement.cpp \
    drugedit.cpp \
    drugmanagement.cpp \
    drugselectdialog.cpp \
    idatabase.cpp \
    login.cpp \
    main.cpp \
    masterview.cpp \
    patientedit.cpp \
    patientmanagement.cpp \
    patientselectdialog.cpp \
    welcome.cpp \
    workreportedit.cpp \
    workreportmanagement.cpp

HEADERS += \
    currloginuserinfo.h \
    diagnosticrecord.h \
    diagnosticrecordedit.h \
    doctoredit.h \
    doctormanagement.h \
    drugedit.h \
    drugmanagement.h \
    drugselectdialog.h \
    idatabase.h \
    login.h \
    masterview.h \
    patientedit.h \
    patientmanagement.h \
    patientselectdialog.h \
    welcome.h \
    workreportedit.h \
    workreportmanagement.h

FORMS += \
    diagnosticrecord.ui \
    diagnosticrecordedit.ui \
    doctoredit.ui \
    doctormanagement.ui \
    drugedit.ui \
    drugmanagement.ui \
    drugselectdialog.ui \
    login.ui \
    masterview.ui \
    patientedit.ui \
    patientmanagement.ui \
    patientselectdialog.ui \
    welcome.ui \
    workreportedit.ui \
    workreportmanagement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
