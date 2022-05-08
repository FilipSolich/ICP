QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cdclass.cc \
    cdclassitem.cc \
    cdclassproperty.cc \
    cdclasswidget.cc \
    cdedge.cc \
    cdedgeitem.cc \
    cdeditor.cc \
    cdeditorscene.cc \
    cdsocket.cc \
    cdsocketitem.cc \
    class.cc \
    diagram.cc \
    diagramtabwidget.cc \
    edgecombobox.cc \
    fileprocessor.cc \
    main.cc \
    mainwindow.cc \
    movecommand.cc \
    sdclass.cc \
    sdedge.cc \
    sdedgeitem.cc \
    sdeditorscene.cc \
    sdsocket.cc \
    sdsocketitem.cc \
    sequenceeditor.cc \
    sequenceitem.cc \
    sequencewidget.cc


HEADERS += \
    cdclass.hh \
    cdclassitem.hh \
    cdclassproperty.hh \
    cdclasswidget.hh \
    cdedge.hh \
    cdedgeitem.hh \
    cdeditor.hh \
    cdeditorscene.hh \
    cdsocket.hh \
    cdsocketitem.hh \
    class.hh \
    diagram.hh \
    diagramtabwidget.hh \
    edgecombobox.hh \
    fileprocessor.hh \
    itemtype.hh \
    mainwindow.hh \
    movecommand.hh \
    sdclass.hh \
    sdedge.hh \
    sdedgeitem.hh \
    sdeditorscene.hh \
    sdsocket.hh \
    sdsocketitem.hh \
    sequenceeditor.hh \
    sequenceitem.hh \
    sequencewidget.hh \
    sequencewidget.hh
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


HEADERS += \
    cdclass.hh \
    cdclassitem.hh \
    cdclassproperty.hh \
    cdclasswidget.hh \
    cdedge.hh \
    cdedgeitem.hh \
    cdeditor.hh \
    cdeditorscene.hh \
    cdsocket.hh \
    cdsocketitem.hh \
    class.hh \
    diagram.hh \
    diagramtabwidget.hh \
    edgecombobox.hh \
    fileprocessor.hh \
    itemtype.hh \
    mainwindow.hh \
    movecommand.hh \
    sdclass.hh \
    sdedge.hh \
    sdedgeitem.hh \
    sdeditorscene.hh \
    sdsocket.hh \
    sdsocketitem.hh \
    sequenceeditor.hh \
    sequenceitem.hh \
    sequencewidget.hh
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
