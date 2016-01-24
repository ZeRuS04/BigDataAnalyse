#include <QtWidgets/QApplication>
//#include "uniformdistribution.h"
#include "normaldistribution.h"

//QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    UniformDistribution ud;

//    ud.run(500000, 40);

    NormalDistribution nd;

    nd.run(500000, 4);


    return a.exec();
}
