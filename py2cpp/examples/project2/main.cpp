#include <fmt/ranges.h>
#include "root2.hpp"

using namespace std;

int main(int argc, const char* args[]) {
    auto a = atof(args[1]);
    auto b = atof(args[2]);
    auto c = atof(args[3]);

    if (a == 0.) {
        fmt::print("The answer is {}.\n", -c/b);
        return 0;
    }
    auto ans = find_roots(a, b, c);
    if (!ans) {
        fmt::print("No real solution.\n");
    }
    else {
        fmt::print("The answer is {}.\n", *ans);
    }
}
