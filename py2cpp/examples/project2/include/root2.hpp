#pragma once

#include <cmath> // import sqrt
#include <cassert>
#include <optional>
#include <utility> // pair

template <typename T>
auto find_roots(const T& a, T b, T c) -> std::optional<std::pair<T, T>> {
    assert(a != 0.);
    b /= a;
    c /= a;
    const auto hb = b / 2.;
    const auto d = hb * hb - c;
    if (d < 0.) {
        return {};
    }
    auto x1 = -hb + (hb < 0. ? std::sqrt(d) : -std::sqrt(d));
    auto x2 = c / x1;
    return { { x1, x2 } };
}

