#include <doctest/doctest.h>  // for Approx, ResultBuilder, TestCase, CHECK

#include <gsl/span>               // for span
#include <lds/low_discr_seq.hpp>  // for circle, halton, sphere, sphere3_hopf

TEST_CASE("circle") {
    auto cgen = lds::circle(2);
    auto [x, y] = cgen();
    CHECK(x == doctest::Approx(0.0));
}

TEST_CASE("halton") {
    unsigned base[] = {2, 3};
    auto hgen = lds::halton(base);
    auto [x, y] = hgen();
    CHECK(x == doctest::Approx(0.5));
}

TEST_CASE("sphere") {
    unsigned base[] = {2, 3};
    auto sgen = lds::sphere(base);
    auto [s0, s1, s2] = sgen();
    CHECK(s0 == doctest::Approx(0.8660254038));
}

TEST_CASE("sphere3_hopf") {
    unsigned base[] = {2, 3, 5};
    auto shfgen = lds::sphere3_hopf(base);
    auto [s0, s1, s2, s3] = shfgen();
    CHECK(s0 == doctest::Approx(-0.2236067977));
}
