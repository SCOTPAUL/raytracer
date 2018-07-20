TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -Wall

SOURCES += \
        main.cpp \
    vec3.cpp \
    ray.cpp \
    sphere.cpp \
    surfacelist.cpp \
    camera.cpp \
    lambertian.cpp

HEADERS += \
    vec3.h \
    ray.h \
    surface.h \
    sphere.h \
    surfacelist.h \
    camera.h \
    material.h \
    lambertian.h
