QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    class.cc \
    classdiagrameditor.cc \
    classitem.cc \
    classwidget.cc \
    diagram.cc \
    diagramtabwidget.cc \
    fileprocessor.cc \
    main.cc \
    mainwindow.cc \
    sequencediagram.cc \
    sequence.cpp \
    socket.cc \
    socketitem.cc

HEADERS += \
    class.hh \
    classdiagrameditor.hh \
    classitem.hh \
    classwidget.hh \
    diagram.hh \
    diagramtabwidget.hh \
    fileprocessor.hh \
    mainwindow.hh \
    sequencediagram.hh \
    sequence.h \
    socket.hh \
    socketitem.hh

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../save_file_syntax.txt
