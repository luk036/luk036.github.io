#include <fmt/ranges.h>
#include <vector>
#include <unordered_set>

int main()
{
    auto S = std::unordered_set{"a", "e", "i", "o", "u", "e"};

    fmt::print("{}\n", S);

    auto i=0U;
    for (auto&& e : S) { // c++20
	fmt::print("{}: {}, \n", i, e);
	i += 1;
    }
}
