const fn permutations(n: u32) -> u32 {
    match n {
        // Base case: 0! = 1
        0 => 1,
        // Recursive case: n! = n * (n-1)!
        _ => n * permutations(n - 1),
    }
}

fn main() {
    const P_5: u32 = permutations(5);
    println!("5! = {}", P_5); // Output: 5! = 120

    const P_0: u32 = permutations(0);
    println!("0! = {}", P_0); // Output: 0! = 1

    const P_3: u32 = permutations(3);
    println!("3! = {}", P_3); // Output: 3! = 6
}
