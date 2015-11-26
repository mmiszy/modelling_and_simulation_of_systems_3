//
// Created by Michal Miszczyszyn on 25/11/15.
//

#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator(integer j, integer k) : j(j), k(k), state(k + 1)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<integer> distribution(1);
    auto random_int = std::bind(distribution, generator);

    for (integer i = 0; i < this->k; ++i)
    {
        this->result.push_back(random_int());
    }
};

integer FibonacciGenerator::calculate(integer i)
{
    static const integer m = (1ull << 32) - 1;

    integer item = (result[i - this->k] | result[i - this->j]) % m;
    result.push_back(item);
    return item;
}

integer FibonacciGenerator::get_next()
{
    ++this->state;
    return this->calculate(this->state);
}
