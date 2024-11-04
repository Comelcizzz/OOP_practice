QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Person.cpp \
    SqliteDBManager.cpp \
    Student.cpp \
    StudentDialog.cpp \
    Teacher.cpp \
    TeacherDialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Person.h \
    SqliteDBManager.h \
    Student.h \
    StudentDialog.h \
    Teacher.h \
    TeacherDialog.h \
    mainwindow.h

FORMS += \
    StudentDialog.ui \
    TeacherDialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
