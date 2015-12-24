#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include "abstractdistribution.h"

class UniformDistribution : public AbstractDistribution
{
public:
    UniformDistribution();

    // AbstractDistribution interface
public:
    double rndFunction(alglib::ae_int_t n);
};

#endif // UNIFORMDISTRIBUTION_H
