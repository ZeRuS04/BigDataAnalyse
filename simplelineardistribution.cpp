#include "simplelineardistribution.h"

SimpLinearDistribution::SimpLinearDistribution()
    : AbstractDistribution()
{
    m_tableName = "simplelinear";
}

double SimpLinearDistribution::generate(alglib::ae_int_t n, int x)
{
//    alglib::hqrndstate st;
//    alglib::hqrndrandomize(st);
//    int v = alglib::hqrndnormal(st) * n;
    int v = rand()%n;
    return (double)v * 4;
}

