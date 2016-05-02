TEMPLATE = app
TARGET = Videobase
CONFIG += c++14

contains(CONFIG, release) {
    DESTDIR = ../Win32/Debug
    MOC_DIR += ./GeneratedFiles/debug
    OBJECTS_DIR += debug
    INCLUDEPATH += ./GeneratedFiles/Debug
} else {
    CONFIG += debug
    DESTDIR = ../Win32/Release
    MOC_DIR += ./GeneratedFiles/release
    OBJECTS_DIR += release
    INCLUDEPATH += ./GeneratedFiles/Release
}
CONFIG -= flat

QT += core sql widgets gui
DEFINES += QT_DLL QT_SQL_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./Implementation \
    ./View
DEPENDPATH += .
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./Implementation/databasehandler.h \
    ./Implementation/rentaleditimpl.h \
    ./Implementation/movieEditImpl.h \
    ./View/rentaleditingdelegate.h \
    ./View/rentalediting.h \
    ./View/movieEditDelegate.h \
    ./View/MovieEdit.h \
    ./View/mainwindow.h
SOURCES += ./main.cpp \
    ./Implementation/movieEditImpl.cpp \
    ./Implementation/databasehandler.cpp \
    ./Implementation/rentaleditimpl.cpp \
    ./View/MovieEdit.cpp \
    ./View/movieEditDelegate.cpp \
    ./View/mainwindow.cpp \
    ./View/rentalediting.cpp \
    ./View/rentaleditingdelegate.cpp
FORMS += ./View/mainwindow.ui \
    ./View/movieedit.ui \
    ./View/rentalediting.ui