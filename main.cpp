#include "MWC.h"
#include "FibonacciGenerator.h"
#include "MixedGenerator.h"


MWC mwc_from_stdin()
{
    integer k, m;
    std::cin >> k >> m;

    integer_vector coefficients(k);
    integer_vector mwcCache(k);
    for (int i = 0; i < k; ++i)
    {
        integer tmp;
        std::cin >> tmp;
        coefficients[i] = tmp;
    }

    for (int i = 0; i < k; ++i)
    {
        integer tmp;
        std::cin >> tmp;
        mwcCache[i] = tmp;
    }

    return MWC(k, m, coefficients, mwcCache);
}

int main()
{
//    auto mwc = mwc_from_stdin();
    integer best_m = (integer) (std::pow(2, 32) - 1);
    auto mwc = MWC(2, best_m, integer_vector(1, 2), integer_vector(3, 4));

    auto fib = FibonacciGenerator();

    auto or_operator = [](integer a, integer b) -> integer { return a | b; };
    auto mixed = MixedGenerator(mwc, fib, or_operator);

//    integer a, b;
//    scanf("%lld-%lld", &a, &b);

    integer a = 1;
    integer b = 100;

    integer i = 0;
    while (i++ < a)
    {
        fib.get_next();
        mwc.get_next();
    }
    for (; i < b; ++i)
    {
        std::cout << fib.get_next() << " | " << mwc.get_next() << " = " << mixed.get_next() << std::endl;
    }
}