#include "abstractdistribution.h"

AbstractDistribution::AbstractDistribution(QObject *parent)
    : QObject(parent)
    , m_tableName("")
{}

bool AbstractDistribution::run(uint n, uint u)
{
    N = n;
    t_m = 0;
    t_s = u;
    if(m_tableName.isEmpty()) {
        qCritical() << "Error: Table name is empty!";
        return false;
    }
    if(!createConnection(m_tableName))
        return false;

//    uint count = getCountData(m_tableName);
//    if(count != 0) {
        m_array.clear();
        if(!clearTable(m_tableName)){
            qCritical() << "Error: Can't clear table";
            return false;
        }
//    }

    for(uint i = 0; i < N; i++) {
        m_array << generate(u, i);
    }

    if (!insertArray(m_array.data(), m_array.length(), m_tableName))
        qWarning() << QString("Warning: Can't append Data to db.table!(%1)").arg(m_tableName);

//    showTable(m_tableName);
    alglib::real_1d_array arr;
    arr.setcontent(m_array.length(), m_array.data());
    calculateBasic(arr);

    qDebug() << chiSquare(40, u);
//    QVector<QPointF> points;
//    for(int i = 0; i < 10000; i++) {
//        double val = m_array.at(i);
//        points << QPointF(val, val * 4 + (generate(100, 0) - 200));
//    }
//    m_chart.newScatter("Linear", points);
//    m_chart.show();

//    QMap<int, int> distrib = getDistribution(m_tableName);
//    QMap<int, int>::const_iterator i = distrib.constBegin();
//    while (i != distrib.constEnd()) {
//        qDebug() << i.key() << "\t" << i.value();
//        ++i;
//    }

//    qSort(m_array);

//    int i = 0;
//    QVector<double> tmp;
//        tmp << val;

//        i++;
//        if(i >= m_array.length() / 21) {
//            i = 0;
//            double mean, variance, skewness, kurtosis;

//            alglib::real_1d_array tmp_arr;
//            tmp_arr.setcontent(tmp.length(), tmp.data());
//            alglib::samplemoments(tmp_arr, mean, variance, skewness, kurtosis);
//            qDebug() << mean;
//            tmp.clear();
//        }
//    }

    return true;
}

void AbstractDistribution::calculateBasic(alglib::real_1d_array arr)
{
//    if(m_tableName.isEmpty()) {
//        qCritical() << "Error: Table name is empty!";
//        return;
//    }
    double variance;
    double skewness;
    double kurtosis;

    alglib::samplemoments(arr, meanValue, variance, skewness, kurtosis);
    alglib::sampleadev(arr, averageDev);

    t_s = averageDev;
    qDebug() << "mean: " << meanValue << endl
             << "average: " << averageDev << endl
             << "variance: " << variance << endl
             << "skewness: " << skewness << endl
             << "kurtosis: " << kurtosis << endl;
}

double AbstractDistribution::chiSquare(uint interCount, int u)
{
    double chi = 0;
    QMap<int, int> distrib = getDistribution(m_tableName);
    QMap<int, int>::const_iterator iter = distrib.constBegin();
    double min = distrib.firstKey();
    double max = distrib.lastKey();
    for(int i = 1; i <= interCount; i++) {
        int gCount = 0;
        double a = (min + (max-min) / interCount * (i-1));
        double b = (min + (max-min) / interCount * (i));

        while (iter != distrib.constEnd()) {
            if((iter.key() >= a) && (iter.key() < b)) {
//                qDebug() << iter.key() << "\t" << iter.value();
                gCount += iter.value();
                ++iter;
            } else {
                break;
            }
        }

        double p = persistance(a, b, interCount);
        double tCount = p * N;
        qDebug() << gCount << tCount;
        chi += ((gCount - tCount) * (gCount - tCount))/tCount;
    }
    return chi;
}
