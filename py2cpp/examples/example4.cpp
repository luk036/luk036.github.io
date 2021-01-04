#include <fmt/core.h>
#include <cstdlib> // import atof
#include <utility> // import swap

int main(int argc, const char* argv[])
{
    auto a = std::atof(argv[1]);
    auto b = std::atof(argv[2]);
    std::swap(a, b);
    fmt::print("The answer is {}.\n", a - b);
}
