mod lds {

    static TWO_PI: f64 = 6.283185307179586;

    fn vdc(mut k: u32, base: u32) -> f64 {
        let mut vdc = 0.0;
        let mut denom = 1.0;
        while k != 0 {
            denom = denom * (base as f64);
            let remainder = k % base;
            k = k / base;
            vdc = vdc + ((remainder as f64) / denom);
        }
        vdc
    }

    pub struct Vdcorput {
        count: u32,
        base: u32,
    }

    impl Vdcorput {
        pub fn new(base: u32) -> Vdcorput {
            Vdcorput { count: 0, base }
        }

        pub fn new_default() -> Vdcorput {
            Vdcorput { count: 0, base: 2 }
        }

        pub fn pop(&mut self) -> f64 {
            self.count = self.count + 1;
            return vdc(self.count, self.base);
        }

        pub fn reseed(&mut self, seed : u32) { self.count = seed; }
    }

    /**
     * @brief Halton sequence generator
     *
     */
    pub struct Halton {
        vdc0: Vdcorput,
        vdc1: Vdcorput
    }

    impl Halton {
        pub fn new(base: &[u32]) -> Halton {
            Halton { 
                vdc0: Vdcorput::new(base[0]), 
                vdc1: Vdcorput::new(base[1]) 
            }
        }

        pub fn pop(&mut self) -> [f64; 2] { [self.vdc0.pop(), self.vdc1.pop()] }

        /**
         * @brief
         *
         * @param seed
         */
        pub fn reseed(&mut self, seed: u32) {
            self.vdc0.reseed(seed);
            self.vdc1.reseed(seed);
        }
    }

    /**
     * @brief Circle sequence generator
     *
     */
    pub struct Circle {
        vdc: Vdcorput,
    }

    impl Circle {
        pub fn new(base: u32) -> Circle {
            Circle { 
                vdc: Vdcorput::new(base),
            }
        }

        pub fn pop(&mut self) -> [f64; 2] {
            // let two_pi = 2.0 * (-1.0 as f64).acos(); // ???
            let theta = self.vdc.pop() * TWO_PI;  // map to [0, 2*pi];
            [theta.sin(), theta.cos()]
        }

        pub fn reseed(&mut self, seed: u32) { self.vdc.reseed(seed); }
    }

    /**
     * @brief Sphere sequence generator
     *
     */
    pub struct Sphere {
        vdc: Vdcorput,
        cirgen: Circle,
    }

    impl Sphere {
        pub fn new(base: &[u32]) -> Sphere {
            Sphere { 
                vdc: Vdcorput::new(base[0]),
                cirgen: Circle::new(base[1]),
            }
        }

        pub fn pop(&mut self) -> [f64; 3] {
            let cosphi = 2.0 * self.vdc.pop() - 1.0;  // map to [-1, 1];
            let sinphi = (1.0 - cosphi * cosphi).sqrt();
            let [c, s] = self.cirgen.pop();
            [sinphi * c, sinphi * s, cosphi]
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
    }

    /**
     * @brief S(3) sequence generator by Hopf
     *
     */
    pub struct Sphere3Hopf {
        vdc0: Vdcorput,
        vdc1: Vdcorput,
        vdc2: Vdcorput,
    }

    impl Sphere3Hopf {
        pub fn new(base: &[u32]) -> Sphere3Hopf {
            Sphere3Hopf { 
                vdc0: Vdcorput::new(base[0]),
                vdc1: Vdcorput::new(base[1]),
                vdc2: Vdcorput::new(base[2]),
            }
        }

        pub fn pop(&mut self) -> [f64; 4] {
            let phi = self.vdc0.pop() * TWO_PI;  // map to [0, 2*pi];
            let psy = self.vdc1.pop() * TWO_PI;  // map to [0, 2*pi];
            let vd = self.vdc2.pop();
            let cos_eta = vd.sqrt();
            let sin_eta = (1.0 - vd).sqrt();
            [cos_eta * psy.cos(), cos_eta * psy.sin(), sin_eta * (phi + psy).cos(),
                    sin_eta * (phi + psy).sin()]
        }

        pub fn reseed(&mut self, seed: u32) {
            self.vdc0.reseed(seed);
            self.vdc1.reseed(seed);
            self.vdc2.reseed(seed);
        }
    }


}  // mod lds

fn main() {
    let base = [2, 3, 5, 7];

    let mut vgen = lds::Vdcorput::new_default();
    for _i in 0 .. 10 {
        println!("{}", vgen.pop());
    }

    let mut cgen = lds::Circle::new(2);
    for _i in 0 .. 10 {
        println!("{:?}", cgen.pop());
    }

    let mut hgen = lds::Halton::new(&base);
    for _i in 0 .. 10 {
        println!("{:?}", hgen.pop());
    }

    let mut sgen = lds::Sphere::new([2, 3]);
    for _i in 0 .. 10 {
        println!("{:?}", sgen.pop());
    }

    let mut s3fgen = lds::Sphere3Hopf::new([2, 3, 5]);
    for _i in 0 .. 10 {
        println!("{:?}", s3fgen.pop());
    }
}

