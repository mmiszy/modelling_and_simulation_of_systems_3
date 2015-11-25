//
// Created by Michal Miszczyszyn on 25/11/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_FIBONACCIGENERATOR_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_FIBONACCIGENERATOR_H


#include "common_header.h"
#include "AbstractRandomGenerator.h"
#include <random>

class FibonacciGenerator : public AbstractRandomGenerator
{
private:
    std::vector<integer> result;
    integer j;
    integer k;

    integer state = 0;

    integer calculate(integer i);

public:
    FibonacciGenerator(integer j = 9739, integer k = 23209);

    integer get_next();
};


#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_FIBONACCIGENERATOR_H
