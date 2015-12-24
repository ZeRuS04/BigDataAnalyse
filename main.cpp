#include "uniformdistribution.h"

int main(int argc, char *argv[])
{
    UniformDistribution ud;

    return ud.generate(500000);
}

