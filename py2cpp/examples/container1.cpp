#include <fmt/ranges.h>
#include <vector>

int main()
{
    auto L = std::vector{"a", "e", "i", "o", "u", "e"};

    fmt::print("{}\n", L);

    auto i = 0U;
    for (auto&& e : L) { // c++20
	fmt::print("{}: {}, \n", i, e);
	i += 1;
    }
}
