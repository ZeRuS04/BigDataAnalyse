#include "normaldistribution.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

NormalDistribution::NormalDistribution()
    : AbstractDistribution()
{
    m_tableName = "normal";
}

double NormalDistribution::generate(alglib::ae_int_t n, int x)
{

    double u;
    double v;
    double s;

    double x1 = 0;
    double x2 = 0;

    for(;;)
    {
        u = fRand(-1.0, 1.0);
        v = fRand(-1.0, 1.0);
        s = u*u + v*v;
        if((s > 0) && (s<=1))
        {
            /*
             * two Sqrt's instead of one to
             * avoid overflow when S is too small
             */
            s = sqrt((-2*log(s))/s);
            x1 = u*s;
            x2 = v*s;
            return round(x1*n);
        }
    }
}

double NormalDistribution::persistance(double a, double b, int u)
{
//    if(a < )

    double erfa = alglib::normaldistribution((a - meanValue) / averageDev);
    double erfb = alglib::normaldistribution((b - meanValue) / averageDev);
    double result = (erfb-erfa);

//    qDebug() << result ;
//    x = a + (b-a)/2;
//    for(double x = a; x <  b; x++) {
//        result = 1 / (t_s * sqrt(2*M_PI)) * exp((-1*(x-t_m)*(x-t_m))/(2*t_s*t_s));
//    }

    return result;
}

