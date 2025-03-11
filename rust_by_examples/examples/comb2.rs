const fn combinations(n: u32, k: u32) -> u32 {
    match (n, k) {
        // If k > n, the result is 0
        (n, k) if k > n => 0,
        // If k >= n, the result is 1
        (n, k) if k >= n => 1,
        // If k == 0 or k == n, the result is 1
        (_, 0) => 1,
        // Otherwise, use the multiplicative formula
        _ => {
            combinations(n - 1, k - 1) + combinations(n - 1, k)
        }
    }
}

fn main() {
    const C_5_2: u32 = combinations(5, 2);
    println!("C(5, 2) = {}", C_5_2); // Output: C(5, 2) = 10

    const C_10_3: u32 = combinations(10, 3);
    println!("C(10, 3) = {}", C_10_3); // Output: C(10, 3) = 120

    const C_4_5: u32 = combinations(4, 5);
    println!("C(4, 5) = {}", C_4_5); // Output: C(4, 5) = 0
}
