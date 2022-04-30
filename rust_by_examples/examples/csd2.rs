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

#include <cmath>   // for fabs, pow, ceil, log2
#include <iosfwd>  // for string
#include <string>  // for basic_string

using std::ceil;
using std::fabs;
using std::log2;
using std::pow;
using std::string;

/**
 * @brief Convert to CSD (Canonical Signed Digit) string representation
 *
 * Original author: Harnesser
 * https://sourceforge.net/projects/pycsd/
 * License: GPL2
 *
 * @param num
 * @param places
 * @return string
 */
auto to_csd(double num, int places = 0) -> string {
    if (num == 0) {
        return "0";
    }
    auto absnum = fabs(num);
    auto n = absnum < 1 ? 0 : int(ceil(log2(absnum * 1.5)));
    auto csd_str = string{absnum < 1 ? "0" : ""};
    auto pow2n = pow(2., n - 1);
    while (n > -places) {
        if (n == 0) {
            csd_str += '.';
        }
        n -= 1;
        auto d = 1.5 * num;
        if (d > pow2n) {
            csd_str += '+';
            num -= pow2n;
        } else if (d < -pow2n) {
            csd_str += '-';
            num += pow2n;
        } else {
            csd_str += '0';
        }
        pow2n /= 2.0;
    }
    return csd_str;
}

/**
 * @brief Convert the CSD string to a decimal
 *
 * @param csd_str
 * @return double
 */
auto to_decimal(const std::string& csd_str) -> double {
    auto num = 0.0;
    auto loc = 0U;
    auto i = 0U;
    for (auto c : csd_str) {
        if (c == '.') {
            loc = i + 1;
        } else {
            num *= 2;
            if (c != '0') {
                if (c == '+')
                    num += 1;
                else if (c == '-')
                    num -= 1;
                // else unknown character
            }
        }
        ++i;
    }
    if (loc != 0U) {
        num /= pow(2.0, csd_str.size() - loc);
    }
    return num;
}

/**
 * @brief Convert to CSD (Canonical Signed Digit) string representation
 *
 * @param[in] num
 * @param[in] nnz number of non-zero
 * @return string
 */
auto to_csdfixed(double num, unsigned int nnz = 4) -> string {
    if (num == 0) {
        return "0";
    }
    auto absnum = fabs(num);
    auto n = absnum < 1 ? 0 : int(ceil(log2(absnum * 1.5)));
    auto csd_str = string{absnum < 1 ? "0" : ""};
    auto pow2n = pow(2., n - 1);
    while (n > 0 || (nnz > 0 && fabs(num) > 1e-100)) {
        if (n == 0) {
            csd_str += '.';
        }
        n -= 1;
        auto d = 1.5 * num;
        if (d > pow2n) {
            csd_str += '+';
            num -= pow2n;
            nnz -= 1;
        } else if (d < -pow2n) {
            csd_str += '-';
            num += pow2n;
            nnz -= 1;
        } else {
            csd_str += '0';
        }
        pow2n /= 2.0;
        if (nnz == 0) {
            num = 0;
        }
    }
    return csd_str;
}
