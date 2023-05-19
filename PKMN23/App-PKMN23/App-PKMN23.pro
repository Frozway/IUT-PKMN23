TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT     += sql
#CONFIG -= qt

SOURCES += \
        electrikpokemon.cpp \
        firepokemon.cpp \
        gamemaker.cpp \
        grasspokemon.cpp \
        main.cpp \
        pokemon.cpp \
        pokemondatabase.cpp \
        trainer.cpp \
        ui.cpp \
        waterpokemon.cpp

HEADERS += \
    electrikpokemon.h \
    firepokemon.h \
    gamemaker.h \
    grasspokemon.h \
    pokemon.h \
    pokemondatabase.h \
    trainer.h \
    ui.h \
    waterpokemon.h
