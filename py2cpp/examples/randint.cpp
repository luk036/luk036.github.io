#include <fmt/core.h>
#include <cstdlib> // import atoi
#include <experimental/random> // import randint

int main(int argc, const char* argv[])
{
    auto a = std::atoi(argv[1]);
    auto b = std::atoi(argv[2]);
    auto c = std::experimental::randint(a, b);
    fmt::print("The answer is {}.\n", c);
}
