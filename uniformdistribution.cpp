#include "uniformdistribution.h"

UniformDistribution::UniformDistribution()
    : AbstractDistribution()
{
    m_tableName = "uniform";
}

double UniformDistribution::rndFunction(alglib::ae_int_t n)
{
    alglib::hqrndstate st;
    alglib::hqrndrandomize(st);
    return (double)alglib::hqrnduniformi(st, n);
}

