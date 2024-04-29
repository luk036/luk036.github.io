#include <fmt/ranges.h>
#include <unordered_map>
#include <any>

/*
template <typename container>
void print_test(const container& C)
{
    fmt::print("[{}]\n", fmt::join(C, ", "));

    for (auto i=0U; auto&& e : C) { // c++20
	fmt::print("{}: {}, \n", i, e);
	++i;
    }
}
*/

int main()
{
    using E = std::pair<int, std::any>;
    auto D = std::unordered_map{E{4, 1}, E{5, 3.4}, E{9, "hello"} };

    // print_test(D);
    fmt::print("{}\n", std::any_cast<const char*>(D[9]));
}
