#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include "abstractdistribution.h"

class UniformDistribution : public AbstractDistribution
{
public:
    UniformDistribution();

    // AbstractDistribution interface
public:
    double generate(alglib::ae_int_t n, int x);
    double persistance(double a, double b, int u);
};

#endif // UNIFORMDISTRIBUTION_H
