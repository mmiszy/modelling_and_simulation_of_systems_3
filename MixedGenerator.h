//
// Created by Michal Miszczyszyn on 25/11/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_MIXEDGENERATOR_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_MIXEDGENERATOR_H


#include "AbstractRandomGenerator.h"
#include "MWC.h"
#include "FibonacciGenerator.h"

class MixedGenerator : public AbstractRandomGenerator
{

private:
    AbstractRandomGenerator &gen1;
    AbstractRandomGenerator &gen2;
    binary_operator_cref operation;

public:
    MixedGenerator(AbstractRandomGenerator &gen1, AbstractRandomGenerator &gen2, binary_operator_cref operation);
    integer get_next();
};


#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_MIXEDGENERATOR_H
