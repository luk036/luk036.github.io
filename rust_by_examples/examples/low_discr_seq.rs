mod lds {

    // static let two_pi = 2 * std::acos(-1.);

    pub fn vdc(u32 mut k, u32 base) -> f64 {
        let mut vdc = 0.0;
        let mut denom = 1.0;
        while k != 0 {
            denom *= base;
            let remainder = k % base;
            k /= base;
            vdc += remainder / denom;
        }
        return vdc;
    }

    pub struct Vdcorput {
        _count: u32;
        _base: u32;
    }

    impl Vdcorput {
        explicit constexpr Vdcorput(u32 base = 2) : _base{base} {}

        pub fn next(&mut self) -> f64 {
            self._count += 1;
            return vdc(self._count, self._base);
        }

        pub fn reseed(&mut self, seed: u32) { self._count = seed; }
    }

    /**
     * @brief Halton sequence generator
     *
     */
    pub struct Halton {
      private:
        Vdcorput vdc0;
        Vdcorput vdc1;

      public:
        /**
         * @brief Construct a new Halton object
         *
         * @param base
         */
        explicit constexpr Halton([u32; 3] base)
            : vdc0(base[0]), vdc1(base[1]) {}

        /**
         * @brief
         *
         * @return auto
         */
        pub fn next(&mut self) -> [f64; 2] { return {self.vdc0(), self.vdc1()}; }

        /**
         * @brief
         *
         * @param seed
         */
        pub fn reseed(&mut self, seed: u32) {
            self.vdc0.reseed(seed);
            self.vdc1.reseed(seed);
        }
    };

    /**
     * @brief Circle sequence generator
     *
     */
    pub struct Circle {
      private:
        Vdcorput vdc;

      public:
        /**
         * @brief Construct a new Circle object
         *
         * @param base
         */
        constexpr explicit Circle(u32 base = 2) : vdc(base) {}

        /**
         * @brief
         *
         * @return auto
         */
        pub fn next(&mut self) -> [f64; 2] {
            let theta = self.vdc() * two_pi;  // map to [0, 2*pi];
            return {std::sin(theta), std::cos(theta)};
        }

        /**
         * @brief
         *
         * @param seed
         */
        pub fn reseed(&mut self, seed: u32) { self.vdc.reseed(seed); }
    };

    /**
     * @brief Sphere sequence generator
     *
     */
    pub struct Sphere {
      private:
        Vdcorput vdc;
        Circle cirgen;

      public:
        /**
         * @brief Construct a new Sphere object
         *
         * @param base
         */
        constexpr Sphere([u32; 3] base)
            : vdc(base[0]), cirgen(base[1]) {}

        /**
         * @brief
         *
         * @return auto
         */
        pub fn next(&mut self) -> [f64; 3] {
            let cosphi = 2 * self.vdc() - 1;  // map to [-1, 1];
            let sinphi = std::sqrt(1 - cosphi * cosphi);
            let [c, s] = self.cirgen();
            return {sinphi * c, sinphi * s, cosphi};
        }

        /**
         * @brief
         *
         * @param seed
         */
        pub fn reseed(&mut self, seed: u32) {
            self.cirgen.reseed(seed);
            self.vdc.reseed(seed);
        }
    };

    /**
     * @brief S(3) sequence generator by Hopf
     *
     */
    pub struct Sphere3_hopf {
      private:
        Vdcorput vdc0;
        Vdcorput vdc1;
        Vdcorput vdc2;

      public:
        /**
         * @brief Construct a new Sphere3 hopf object
         *
         * @param base
         */
        constexpr explicit Sphere3_hopf([u32; 3] base)
            : vdc0(base[0]), vdc1(base[1]), vdc2(base[2]) {}

        /**
         * @brief
         *
         * @return auto
         */
        pub fn next(&mut self) -> [f64; 4] {
            let phi = self.vdc0() * two_pi;  // map to [0, 2*pi];
            let psy = self.vdc1() * two_pi;  // map to [0, 2*pi];
            // auto zzz = self.vdc2() * 2 - 1; // map to [-1., 1.];
            // auto eta = std::acos(zzz) / 2;
            // auto cos_eta = std::cos(eta);
            // auto sin_eta = std::sin(eta);
            let vd = self.vdc2();
            let cos_eta = std::sqrt(vd);
            let sin_eta = std::sqrt(1 - vd);
            return {cos_eta * std::cos(psy), cos_eta * std::sin(psy), sin_eta * std::cos(phi + psy),
                    sin_eta * std::sin(phi + psy)};
        }

        /**
         * @brief
         *
         * @param seed
         */
        pub fn reseed(&mut self, seed: u32) {
            self.vdc0.reseed(seed);
            self.vdc1.reseed(seed);
            self.vdc2.reseed(seed);
        }
    };

}  // mod lds

#include <doctest/doctest.h>  // for Approx, ResultBuilder, TestCase, CHECK

#include <gsl/span>               // for span
#include <lds/low_discr_seq.hpp>  // for Circle, Halton, Sphere, Sphere3_hopf

TEST_CASE("Circle") {
    auto cgen = lds::Circle(2);
    auto [x, y] = cgen();
    CHECK(x == doctest::Approx(0.0));
}

TEST_CASE("Halton") {
    u32 base[] = {2, 3};
    auto hgen = lds::Halton(base);
    auto [x, y] = hgen();
    CHECK(x == doctest::Approx(0.5));
}

TEST_CASE("Sphere") {
    u32 base[] = {2, 3};
    auto sgen = lds::Sphere(base);
    auto [s0, s1, s2] = sgen();
    CHECK(s0 == doctest::Approx(0.8660254038));
}

TEST_CASE("Sphere3_hopf") {
    u32 base[] = {2, 3, 5};
    auto shfgen = lds::Sphere3_hopf(base);
    auto [s0, s1, s2, s3] = shfgen();
    CHECK(s0 == doctest::Approx(-0.2236067977));
}
