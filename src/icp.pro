QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    class.cc \
    classdiagrameditor.cc \
    classdiagrameditorscene.cc \
    classitem.cc \
    classwidget.cc \
    diagram.cc \
    diagramtabwidget.cc \
    edge.cc \
    edgecombobox.cc \
    edgeitem.cc \
    fileprocessor.cc \
    main.cc \
    mainwindow.cc \
    sdsocket.cpp \
    sdsocketitem.cpp \
    sequencediagram.cc \
    sequence.cpp \
    sequenceitem.cpp \
    sequencemsg.cpp \
    sequencewidget.cpp \
    socket.cc \
    socketitem.cc

HEADERS += \
    class.hh \
    classdiagrameditor.hh \
    classdiagrameditorscene.hh \
    classitem.hh \
    classwidget.hh \
    diagram.hh \
    diagramtabwidget.hh \
    edge.hh \
    edgecombobox.hh \
    edgeitem.hh \
    fileprocessor.hh \
    itemtype.hh \
    mainwindow.hh \
    sdsocket.h \
    sdsocketitem.h \
    sequencediagram.hh \
    sequence.h \
    sequenceitem.h \
    sequencemsg.h \
    sequencewidget.h \
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
