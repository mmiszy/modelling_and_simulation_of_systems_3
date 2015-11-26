//
// Created by Michal Miszczyszyn on 25/11/15.
//

#ifndef MODELLING_AND_SIMULATION_OF_SYSTEMS_COMMON_HEADER_H
#define MODELLING_AND_SIMULATION_OF_SYSTEMS_COMMON_HEADER_H

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <regex>

using integer = uint64_t;
using integer_vector_cref = const std::vector<integer> &;
using integer_vector = std::vector<integer>;
using binary_operator_cref = const std::function <integer (integer a, integer b)>&;

#endif //MODELLING_AND_SIMULATION_OF_SYSTEMS_COMMON_HEADER_H
