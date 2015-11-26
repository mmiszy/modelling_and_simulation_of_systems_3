#include "MWC.h"
#include "FibonacciGenerator.h"
#include "MixedGenerator.h"
#include "common_header.h"


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

int main(int argc, char *argv[])
{
    integer best_m = (integer) (std::pow(2, 32) - 1);
    auto mwc = MWC(2, best_m, integer_vector(1, 2), integer_vector(3, 4));

    auto fib = FibonacciGenerator();

    auto and_operator = [](integer a, integer b) -> integer { return a & b; };
    auto mixed = MixedGenerator(mwc, fib, and_operator);

    integer a = 1;
    integer b = 10;


    if (argc >= 2)
    {
        std::regex pattern("(\\d+)-(\\d+)");
        std::smatch base_match;
        if (std::regex_match(std::string(argv[1]), base_match, pattern))
        {

            if (base_match.size() == 3)
            {
                a = (integer) atoll(base_match[1].str().c_str());
                b = (integer) atoll(base_match[2].str().c_str());
            }
        }
    }

    integer i = 0;
    for (; i < a; ++i)
    {
        mixed.get_next();
    }
    for (; i < b; ++i)
    {
        std::cout << mixed.get_next() << std::endl;
    }
}