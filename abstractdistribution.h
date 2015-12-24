#ifndef ABSTRACTDISTRIBUTION_H
#define ABSTRACTDISTRIBUTION_H

#include <QObject>
#include <QVector>
#include "cpp/src/statistics.h"
#include "cpp/src/ap.h"
#include "database.h"

class AbstractDistribution : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDistribution(QObject *parent = 0);

    virtual double rndFunction(alglib::ae_int_t n) = 0;

    bool generate(uint n);
    void calculateBasic(alglib::real_1d_array arr);

    double averageDev;
    double meanValue;
protected:
    QString m_tableName;
    QVector<double> m_array;
};

#endif // ABSTRACTDISTRIBUTION_H
