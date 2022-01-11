QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = Snake
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
    Login.cpp \
    food.cpp \
    game_screen.cpp \
    snake.cpp

HEADERS += \
    Login.h \
    food.h \
    game_screen.h \
    snake.h

FORMS += \
    Login.ui \
    game_screen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
food.png \
food1.png \
    images/cherry.png \
images/food.png \
images/food2.png \
    images/logo.png \
    images/mango.png \
    images/mouse.png \
images/snake.png \
snake.png

RESOURCES += \
    images.qrc
