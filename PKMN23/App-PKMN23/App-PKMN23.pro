TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT     += sql
#CONFIG -= qt

SOURCES += \
        database.cpp \
        electrikpokemon.cpp \
        firepokemon.cpp \
        gamemaker.cpp \
        grasspokemon.cpp \
        main.cpp \
        pokemon.cpp \
        trainer.cpp \
        ui.cpp \
        waterpokemon.cpp

HEADERS += \
    database.h \
    electrikpokemon.h \
    firepokemon.h \
    gamemaker.h \
    grasspokemon.h \
    pokemon.h \
    trainer.h \
    ui.h \
    waterpokemon.h
