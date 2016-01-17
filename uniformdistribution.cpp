#include "uniformdistribution.h"

UniformDistribution::UniformDistribution()
    : AbstractDistribution()
{
    m_tableName = "uniform";
}

double UniformDistribution::generate(alglib::ae_int_t n, int x)
{
//    alglib::hqrndstate st;
//    alglib::hqrndrandomize(st);
//    int v = alglib::hqrnduniformi(st, n);
    int v = rand()%n;
    return (double)v;
}

