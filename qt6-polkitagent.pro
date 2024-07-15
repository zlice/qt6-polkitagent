QT       += core gui dbus widgets
TEMPLATE = app
TARGET = qt6-polkitagent

DBUS_ADAPTORS = com.iskrembilen.polkitAuthAgent.xml

SOURCES += main.cpp\
    polkitinterface.cpp \
    authenticate.cpp

HEADERS  += \
    polkitinterface.h \
    authenticate.h

FORMS    += \
    authenticate.ui

LIBS += -lpolkit-qt6-agent-1 -lpolkit-qt6-core-1 -lX11

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target
