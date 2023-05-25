QT += testlib
QT -= gui
QT += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gameunittests.cpp \
    ../App-PKMN23/electrikpokemon.cpp \
    ../App-PKMN23/firepokemon.cpp \
    ../App-PKMN23/gamemaker.cpp \
    ../App-PKMN23/grasspokemon.cpp \
    ../App-PKMN23/pokemon.cpp \
    ../App-PKMN23/pokemondatabase.cpp \
    ../App-PKMN23/trainer.cpp \
    ../App-PKMN23/ui.cpp \
    ../App-PKMN23/waterpokemon.cpp

HEADERS += \
    ../App-PKMN23/UI.h \
    ../App-PKMN23/electrikpokemon.h \
    ../App-PKMN23/firepokemon.h \
    ../App-PKMN23/gamemaker.h \
    ../App-PKMN23/grasspokemon.h \
    ../App-PKMN23/pokemon.h \
    ../App-PKMN23/pokemondatabase.h \
    ../App-PKMN23/trainer.h \
    ../App-PKMN23/waterpokemon.h
