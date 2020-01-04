QT       += core gui dbus x11extras widgets
TEMPLATE = app
TARGET = qt-polkitagent

DBUS_ADAPTORS = com.iskrembilen.polkitAuthAgent.xml

SOURCES += main.cpp\
    polkitinterface.cpp \
    authenticate.cpp

HEADERS  += \
    polkitinterface.h \
    authenticate.h

FORMS    += \
    authenticate.ui

LIBS += -lpolkit-qt5-agent-1 -lpolkit-qt5-core-1 -lX11

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target
