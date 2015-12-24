QT += core sql

TARGET = BigDataAnalyse
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    abstractdistribution.cpp \
    uniformdistribution.cpp \
    cpp/src/statistics.cpp \
    cpp/src/alglibinternal.cpp \
    cpp/src/alglibmisc.cpp \
    cpp/src/ap.cpp \
    cpp/src/dataanalysis.cpp \
    cpp/src/diffequations.cpp \
    cpp/src/fasttransforms.cpp \
    cpp/src/integration.cpp \
    cpp/src/interpolation.cpp \
    cpp/src/linalg.cpp \
    cpp/src/optimization.cpp \
    cpp/src/solvers.cpp \
    cpp/src/specialfunctions.cpp

HEADERS += \
    database.h \
    abstractdistribution.h \
    cpp/src/statistics.h \
    uniformdistribution.h \
    cpp/src/alglibinternal.h \
    cpp/src/alglibmisc.h \
    cpp/src/ap.h \
    cpp/src/dataanalysis.h \
    cpp/src/diffequations.h \
    cpp/src/fasttransforms.h \
    cpp/src/integration.h \
    cpp/src/interpolation.h \
    cpp/src/linalg.h \
    cpp/src/optimization.h \
    cpp/src/solvers.h \
    cpp/src/specialfunctions.h \
    cpp/src/stdafx.h

