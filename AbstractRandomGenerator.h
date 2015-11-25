//
// Created by Michal Miszczyszyn on 25/11/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_RANDOMGENERATOR_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_RANDOMGENERATOR_H

#include "common_header.h"

class AbstractRandomGenerator
{
public:
    virtual integer get_next() = 0;
};

#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_RANDOMGENERATOR_H
