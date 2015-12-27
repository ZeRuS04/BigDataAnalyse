#include "abstractdistribution.h"

AbstractDistribution::AbstractDistribution(QObject *parent)
    : QObject(parent)
    , m_tableName("")
{}

bool AbstractDistribution::generate(uint n)
{
//    if(m_tableName.isEmpty()) {
//        qCritical() << "Error: Table name is empty!";
//        return false;
//    }
//    if(!createConnection(m_tableName))
//        return false;

    uint count = m_array.size()/*getCountData(m_tableName)*/;
    if(count != 0) {
        m_array.clear();
//        if(!clearTable(m_tableName)){
//            qCritical() << "Error: Can't clear table";
//            return false;
//        }
    }
    for(uint i = 0; i < n; i++) {
        m_array << rndFunction(500000);
//        if (!insertData(rndFunction(500000), i, m_tableName))
//            qWarning() << QString("Warning: Can't append Data to db.table!(%1, %2)").arg(i).arg(m_tableName);
    }

    alglib::real_1d_array arr;
    arr.setcontent(m_array.length(), m_array.data());
    calculateBasic(arr);
    int i = 0;
    QVector<double> tmp;
    foreach(double val, m_array) {
        tmp << val;

        i++;
        if(i >= m_array.length() / 21) {
            i = 0;
            double mean, variance, skewness, kurtosis;

            alglib::real_1d_array tmp_arr;
            tmp_arr.setcontent(tmp.length(), tmp.data());
            alglib::samplemoments(tmp_arr, mean, variance, skewness, kurtosis);
            qDebug() << mean;
            tmp.clear();
        }
    }

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

    qDebug() << "mean: " << meanValue << endl
             << "average: " << averageDev << endl
             << "variance: " << variance << endl
             << "skewness: " << skewness << endl
             << "kurtosis: " << kurtosis << endl;
}
