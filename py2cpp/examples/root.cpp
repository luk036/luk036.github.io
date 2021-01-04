#include <fmt/core.h>
#include <cstdlib> // import atof
#include <cmath> // import sqrt

int main(int argc, const char* argv[])
{
    using namespace std;

    auto a = atof(argv[1]);
    auto b = atof(argv[2]);
    auto c = atof(argv[3]);
    if (a == 0.) {
        fmt::print("The root is {}.\n", -c / b);
	fmt::print("No real solution.");
        return 0;
    }
    b /= a;
    c /= a;
    auto hb = b / 2.;
    auto d = hb * hb - c;
    if (d < 0.) {
	fmt::print("No real solution.");
        return 0;
    }
    auto x1 = -hb + (hb < 0. ? sqrt(d) : -sqrt(d));
    auto x2 = c / x1;
    fmt::print("The roots are {} and {}.\n", x1, x2);
}
