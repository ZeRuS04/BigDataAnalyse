QT += core sql charts gui widgets

TARGET = BigDataAnalyse

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
    cpp/src/specialfunctions.cpp \
    normaldistribution.cpp \
    chartview.cpp

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
    cpp/src/stdafx.h \
    normaldistribution.h \
    chartview.h

