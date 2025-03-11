fn main() {
    let a = 3;
    println!("The answer is {}", a);

    let tup = ("a", "u", "e", 7, 3.4);
    println!("{:?}", tup);

    let arr = [2, 3, 5, 7];
    for (i, e) in arr.iter().enumerate() {
        println!("{}: {}", i, e);
    }
}
