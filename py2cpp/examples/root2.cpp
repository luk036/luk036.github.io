#include <cmath> // import sqrt
#include <fmt/ranges.h>
#include <cassert>
#include <optional>
#include <utility> // pair

using namespace std;

template <typename T>
auto find_roots(const T& a, T b, T c) -> optional<pair<T, T>> {
    assert(a != 0.);
    b /= a;
    c /= a;
    const auto hb = b / 2.;
    const auto d = hb * hb - c;
    if (d < 0.) {
        return {};
    }
    auto x1 = -hb + (hb < 0. ? sqrt(d) : -sqrt(d));
    auto x2 = c / x1;
    return { { x1, x2 } };
}


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
