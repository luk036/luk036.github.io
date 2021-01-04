#include <fmt/ranges.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

template <typename container>
void print_test(const container& C)
{
    fmt::print("{}\n", C);

    auto i = 0U;
    for (auto&& e : C) { // c++20
	fmt::print("{}: {}, \n", i, e);
	i += 1;
    }
}


int main()
{
    auto L = std::vector{"a", "e", "i", "o", "u", "e"};
    auto S = std::unordered_set{"a", "e", "i", "o", "u", "e"};

    using E = std::pair<int, double>;
    auto D = std::unordered_map{E{4, 1.2}, E{5, 2.3}};

    print_test(L);
    print_test(S);
    print_test(D);
}
