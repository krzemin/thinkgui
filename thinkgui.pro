QT += widgets

FORMS += \
    forms/thinkgui.ui \
    forms/cpuwidget.ui \
    forms/sensorwidget.ui \
    forms/fanwidget.ui \
    forms/batterywidget.ui \
    forms/advancedbatterydialog.ui

SOURCES += \
    src/main.cpp \
    src/thinkgui.cpp \
    src/cpuwidget.cpp \
    src/sensorwidget.cpp \
    src/fanwidget.cpp \
    src/batterywidget.cpp \
    src/fileio.cpp \
    src/config.cpp \
    src/sensormodel.cpp \
    src/fanmodel.cpp \
    src/cpumodel.cpp \
    src/batterymodel.cpp \
    src/advancedbatterydialog.cpp

HEADERS += \
    src/thinkgui.h \
    src/cpuwidget.h \
    src/sensorwidget.h \
    src/fanwidget.h \
    src/batterywidget.h \
    src/fileio.h \
    src/cpuconfig.h \
    src/config.h \
    src/sensorconfig.h \
    src/fanconfig.h \
    src/batteryconfig.h \
    src/sensormodel.h \
    src/cpumodel.h \
    src/batterymodel.h \
    src/advancedbatterydialog.h

RESOURCES += \
    res/resources.qrc

UI_DIR = .tmp
MOC_DIR = .tmp
RCC_DIR = .tmp
OBJECTS_DIR = .tmp

INSTALL_PREFIX = /usr
BIN_DIR = "$${INSTALL_PREFIX}/bin"
SHARE_DIR = "$${INSTALL_PREFIX}/share"
DOC_DIR = "$${SHARE_DIR}/doc/$${TARGET}"

target.path = "$${BIN_DIR}"
doc.path = "$${DOC_DIR}"
doc.files = doc/README doc/thinkgui.ini.sample
INSTALLS = target \
 doc
