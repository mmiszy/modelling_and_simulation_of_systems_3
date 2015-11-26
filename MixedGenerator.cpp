//
// Created by Michal Miszczyszyn on 25/11/15.
//

#include "MixedGenerator.h"

MixedGenerator::MixedGenerator(AbstractRandomGenerator &gen1, AbstractRandomGenerator &gen2, binary_operator_cref operation) : gen1(gen1), gen2(gen2), operation(operation) {
}

integer MixedGenerator::get_next()
{
    integer i = this->gen1.get_next();
    integer next = this->gen2.get_next();
//    std::cout << i << " & " << next << " ";
    return this->operation(i, next);
}
