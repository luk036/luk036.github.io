#include <doctest/doctest.h>
#include <root2.hpp>

TEST_CASE("check root2()")
{
    auto ans = find_roots(1., -2., 1.);
    CHECK(ans->first == doctest::Approx(1));
}
