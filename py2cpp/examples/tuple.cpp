#include <fmt/ranges.h>
#include <tuple>

template <std::size_t I = 0, typename... Tp>
void print_test(const std::tuple<Tp...>& t)
{
    if constexpr (I < sizeof...(Tp)) {
	fmt::print("{}: {}, \n", I, std::get<I>(t));
	print_test<I + 1, Tp...>(t);
    }
}

int main()
{
    auto t = std::tuple{"a", "u", "e", 3, 4.5};
    fmt::print("{}\n", t);
    print_test(t);
}
