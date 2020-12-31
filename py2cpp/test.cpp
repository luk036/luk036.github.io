#include "low_discr_seq.hpp"
#include <fmt/ranges.h>

int main()
{
    unsigned b[] = {2, 5, 7, 3};
    auto hgen = lds::halton_n(3, b);
    for (auto i = 0U; i != 10; ++i)
    {
	fmt::print("{}\n", hgen());
    }
}

