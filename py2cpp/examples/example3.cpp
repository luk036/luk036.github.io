#include <fmt/core.h>
#include <cstdlib>  // import atoi

int main(int argc, const char* argv[])
{
    auto a = std::atoi(argv[1]);
    auto b = std::atoi(argv[2]);
    fmt::print("The answer is {}.\n", a + b);
}
