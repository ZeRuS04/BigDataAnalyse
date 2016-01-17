#include "normaldistribution.h"

NormalDistribution::NormalDistribution()
    : AbstractDistribution()
{
    m_tableName = "normal";
}

double NormalDistribution::generate(alglib::ae_int_t n, int x)
{
    alglib::hqrndstate st;
    alglib::hqrndrandomize(st);
    int v = alglib::hqrndnormal(st) * n;
//    int v = rand()%n;
    return (double)v;
}

