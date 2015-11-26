//
// Created by Michal Miszczyszyn on 25/11/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_MWC_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_MWC_H


#include "common_header.h"
#include "AbstractRandomGenerator.h"

class MWC : public AbstractRandomGenerator
{
private:
    integer_vector cnCache;
    integer_vector mwcCache;
    integer_vector coefficients;

    integer k;
    integer m;

    integer calculateCn(integer n, integer k, integer m, integer_vector_cref a);

    integer calculateMWCn(integer n, integer k, integer m, integer_vector_cref a);

    integer calculate(integer i);

    integer state = 0;

public:
    MWC(integer k, integer m);

    MWC(integer k, integer m, integer_vector_cref coefficients, integer_vector_cref mwc);

    integer get_next();
};


#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_MWC_H
