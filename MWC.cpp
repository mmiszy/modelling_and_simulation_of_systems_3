//
// Created by Michal Miszczyszyn on 25/11/15.
//

#include "MWC.h"
#include "common_header.h"

MWC::MWC(integer k, integer m, const std::vector<integer> &coefficients, const std::vector<integer> &mwc) : mwcCache(mwc), coefficients(coefficients), k(k), m(m)
{
}

integer MWC::calculateCn(integer n, integer k, integer m, integer_vector_cref a)
{
    if (n == 0)
    {
        return 0;
    }
    else if (this->cnCache.size() > n)
    {
        return this->cnCache[n];
    } else {
        while (this->cnCache.size() <= n) {
            this->cnCache.push_back(0);
        }
    }

    integer sum = 0;

    for (integer i = 0; i < k; ++i)
    {
        sum += a[i] * this->mwcCache[n - i - 1] + this->cnCache[n - 1];
    }

    this->cnCache.push_back((integer) std::floor(sum / m));
    return this->cnCache[n];
}

integer MWC::calculateMWCn(integer n, integer k, integer m, integer_vector_cref a)
{
    if (this->mwcCache.size() > n)
    {
        return this->mwcCache[n];
    }

    integer cn = this->calculateCn(n - 1, k, m, a);

    integer sum = 0;
    for (integer i = 0; i < k; ++i)
    {
        sum += (a[i] * this->calculateMWCn(n - i - 1, k, m, a) + cn) % m;
    }

    this->mwcCache.push_back(sum);

    return sum;
}

integer MWC::calculate(integer i)
{
    return calculateMWCn(i, this->k, this->m, this->coefficients);
}

integer MWC::get_next()
{
    ++this->state;
    return this->calculate(this->state);
}
