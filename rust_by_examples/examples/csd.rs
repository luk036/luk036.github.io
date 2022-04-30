/**
 Canonical Signed Digit Functions

 Handles:
  * Decimals
  *
  *

 eg, +00-00+000.0 or 0.+0000-00+
 Where: '+' is +1
        '-' is -1

 Harnesser
 License: GPL2
*/

/**
 * @brief Convert to CSD (Canonical Signed Digit) String representation
 *
 * Original author: Harnesser
 * https://sourceforge.net/projects/pycsd/
 * License: GPL2
 *
 * @param num
 * @param places
 * @return String
 */
fn to_csd(mut num: f64, places: i32) -> String {
    if num == 0.0 {
        return String::from("0");
    }
    let absnum = num.abs();
    let nn = (absnum * 1.5).log2().ceil() as i32;
    let mut n = if absnum < 1.0 { 0 } else { nn };
    let str = if absnum < 1.0 { "0" } else { "" };
    let mut csd_str = String::from(str);
    let mut pow2n = (2.0_f64).powf((n - 1) as f64);
    while n > -places {
        if n == 0 {
            csd_str.push('.');
        }
        n = n - 1;
        let d = 1.5 * num;
        if d > pow2n {
            csd_str.push('+');
            num = num - pow2n;
        } else if d < -pow2n {
            csd_str.push('-');
            num = num + pow2n;
        } else {
            csd_str.push('0');
        }
        pow2n = pow2n / 2.0;
    }
    csd_str
}

/**
 * @brief Convert the CSD String to a decimal
 *
 * @param csd_str
 * @return f64
 */
fn to_decimal(csd_str: &String) -> f64 {
    let mut num: f64 = 0.0;
    let mut loc: u32 = 0;
    let mut i: u32 = 0;
    for c in csd_str.chars() {
        if c == '0' {
            num = num * 2.0;
        } else if c == '+' {
            num = num * 2.0 + 1.0;
        } else if c == '-' {
            num = num * 2.0 - 1.0;
        } else if c == '.' {
            loc = i + 1;
        } // else unknown character
        i = i + 1;
    }
    if loc != 0 {
        num = num / (2.0_f64).powf(((csd_str.len() as u32) - loc) as f64);
    }
    return num;
}

/**
 * @brief Convert to CSD (Canonical Signed Digit) String representation
 *
 * @param[in] num
 * @param[in] nnz number of non-zero
 * @return String
 */
fn to_csdfixed(mut num: f64, mut nnz: u32) -> String {
    if num == 0.0 {
        return String::from("0");
    }
    let absnum = num.abs();
    let nn = (absnum * 1.5).log2().ceil() as i32;
    let mut n = if absnum < 1.0 { 0 } else { nn };
    let str = if absnum < 1.0 { "0" } else { "" };
    let mut csd_str = String::from(str);
    let mut pow2n = (2.0_f64).powf((n - 1) as f64);
    while n > 0 || (nnz > 0 && num.abs() > 1e-100) {
        if n == 0 {
            csd_str.push('.');
        }
        n = n - 1;
        let d = 1.5 * num;
        if d > pow2n {
            csd_str.push('+');
            num = num - pow2n;
            nnz = nnz - 1;
        } else if d < -pow2n {
            csd_str.push('-');
            num = num + pow2n;
            nnz = nnz - 1;
        } else {
            csd_str.push('0');
        }
        pow2n = pow2n / 2.0;
        if nnz == 0 {
            num = 0.0;
        }
    }
    csd_str
}

fn main() {
    println!("CHECK: +00-00.+0 == {}", to_csd(28.5, 2));
    println!("CHECK: 0.-0 == {}", to_csd(-0.5, 2));

    println!("CHECK: 28.5 == {}", to_decimal(&String::from("+00-00.+")));
    println!("CHECK: -0.5 == {}", to_decimal(&String::from("0.-")));

    println!("CHECK: +00-00.+ == {}", to_csdfixed(28.5, 4));
    println!("CHECK: 0.- == {}", to_csdfixed(-0.5, 4));
}
