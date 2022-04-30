fn vdc(mut k: u32, base: u32) -> f64 {
    let mut vdc = 0.0;
    let mut denom = 1.0;
    while k != 0 {
        denom *= base as f64;
        let rem = k % base;
        k /= base;
        vdc += (rem as f64) / denom;
    }
    vdc  // <- note!
}

fn main() {
    for k in 1..11 { 
        println!("{}", vdc(k, 2));
    }
}

