#ifndef ABSTRACTDISTRIBUTION_H
#define ABSTRACTDISTRIBUTION_H

#include <QObject>
#include <QVector>
#include "cpp/src/statistics.h"
#include "cpp/src/ap.h"
#include "qmath.h"
#include "database.h"
#include "chartview.h"

class AbstractDistribution : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDistribution(QObject *parent = 0);

    virtual double generate(alglib::ae_int_t n, int x) = 0;

    virtual double persistance(double a, double b, int u) = 0;

    bool run(uint n, uint u);
    void calculateBasic(alglib::real_1d_array arr);

    double chiSquare(uint interCount, int u);

    double averageDev;
    double meanValue;

    double t_m;
    double t_s;
    int N;
protected:
    QString m_tableName;
    QVector<double> m_array;
    ChartView m_chart;
};

#endif // ABSTRACTDISTRIBUTION_H
