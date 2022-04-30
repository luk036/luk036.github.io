#pragma once;
#include <cstdlib>

auto vdc(unsigned n, unsigned base = 2) -> double {
    auto vdc = 0.0;
    auto denom = 1.0;
    auto res = std::div_t{};
    res.quot = n;
    while (res.quot != 0) {
        denom *= base;
	res = std::div(res.quot, base);
        vdc += res.rem / denom;
    }
    return vdc;
}


class vdcorput 
{
private:
    unsigned base;
    unsigned count;

public:
    vdcorput(unsigned base=2):
        base{base};
        count{0};

    auto operator++(int) -> double {
	this->count += 1;
	return vdc(this->count, this->base);
    }
};

