const fn combinations(n: u32, k: u32) -> u32 {
    if k > n {
        return 0;
    }

    // Use the multiplicative formula to avoid large intermediate values
    let k = if k > n - k { n - k } else { k }; // Take advantage of symmetry
    let mut result = 1;

    let mut i = 1;
    while i <= k {
        result = (result * (n - k + i)) / i;
        i += 1;
    }

    result
}

fn main() {
    const C_5_2: u32 = combinations(5, 2);
    println!("C(5, 2) = {}", C_5_2);
}
