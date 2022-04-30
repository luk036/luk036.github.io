fn find_roots(b: f64, c: f64) -> Option<(f64, f64)> {
    let h = b / 2.0;
    let d = h * h - c;
    if d < 0.0 {
        return None;
    } 
    let sqrd = d.sqrt();
    let x1 = -h + (if h < 0.0 { sqrd } else { -sqrd });
    let x2 = c / x1;
    Some((x1, x2))
}

fn main() {
    let a = 1.0;
    let b = 5.0;
    let c = 6.0;

    let ans = find_roots(b/a, c/a);
    if let Some(value) = ans {
        println!("The answers are {:?}", value);
    }
    else {
        println!("There is no real solution");
    }
}
