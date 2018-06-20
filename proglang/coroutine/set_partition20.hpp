#ifndef SET_PARTITION20
#define SET_PARTITION20 1

// Set Partition
//
// A set partition of the set [n] = {1,2,3,...,n} is a collection B0,
// B1, ... Bj of disjoint subsets of [n] whose union is [n]. Each Bj
// is called a block. Below we show the partitions of [4]. The periods
// separtate the individual sets so that, for example, 1.23.4 is the
// partition {{1},{2,3},{4}}.
//   1 block:  1234
//   2 blocks: 123.4   124.3   134.2   1.234   12.34   13.24   14.23
//   3 blocks: 1.2.34  1.24.3  14.2.3  13.2.4  12.3.4
//   4 blocks: 1.2.3.4
//
// Each partition above has its blocks listed in increasing order of
// smallest element; thus block 0 contains element 1, block1 contains
// the smallest element not in block 0, and so on. A Restricted Growth
// string (or RG string) is a sring a[1..n] where a[i] is the block in
// whcih element i occurs. Restricted Growth strings are often called
// restricted growth functions. Here are the RG strings corresponding
// to the partitions shown above.
//
//   1 block:  0000
//   2 blocks: 0001, 0010, 0100, 0111, 0011, 0101, 0110
//   3 blocks: 0122, 0121, 0112, 0120, 0102,
//
// ...more
//
// Reference:
// Frank Ruskey. Simple combinatorial Gray codes constructed by
// reversing sublists. Lecture Notes in Computer Science, #762,
// 201-208. Also downloadable from
// http://webhome.cs.uvic.ca/~ruskey/Publications/SimpleGray/SimpleGray.html
//
#include <cassert>
#include <cctype>
#include <cstdio>
#include <functional>
#include <utility>

#include "recursive_generator.hpp"
#include <experimental/coroutine>

using namespace cppcoro;

typedef std::tuple<int, int> ret_t;

// Stirling number of second kind. Note that this function is for
// testing purpose only and is slow because of reducdant calculation.
constexpr int stirling2nd(int n, int k) {
    if (k >= n || k <= 1)
        return 1;
    return stirling2nd(n - 1, k - 1) + k * stirling2nd(n - 1, k);
}

recursive_generator<ret_t> Move(int x, int y) {
    co_yield std::make_tuple(x, y);
}

// The lists S(n,k,0) and S(n,k,1) satisfy the following properties.
// 1. Successive RG sequences differ in exactly one position.
// 2. first(S(n,k,0)) = first(S(n,k,1)) = 0^{n-k}0123...(k-1)
// 3. last(S(n,k,0)) = 0^{n-k}12...(k-1)0
// 4. last(S(n,k,1)) = 012...(k-1)0^{n-k}
// Note that first(S'(n,k,p)) = last(S(n,k,p))

recursive_generator<ret_t> GEN0_even(int n, int k);
recursive_generator<ret_t> NEG0_even(int n, int k);
recursive_generator<ret_t> GEN1_even(int n, int k);
recursive_generator<ret_t> NEG1_even(int n, int k);
recursive_generator<ret_t> GEN0_odd(int n, int k);
recursive_generator<ret_t> NEG0_odd(int n, int k);
recursive_generator<ret_t> GEN1_odd(int n, int k);
recursive_generator<ret_t> NEG1_odd(int n, int k);

recursive_generator<ret_t> set_partition_seq(int n, int k) {
    if (k % 2 == 0)
        co_yield GEN0_even(n, k);
    else
        co_yield GEN0_odd(n, k);
}

// S(n,k,0) even k
recursive_generator<ret_t> GEN0_even(int n, int k) {
    if (k > 0 && k < n) {
        co_yield GEN0_odd(n - 1, k - 1); // S(n-1, k-1, 0).(k-1)
        co_yield Move(n - 1, k - 1);
        co_yield GEN1_even(n - 1, k); // S(n-1, k, 1).(k-1)
        co_yield Move(n, k - 2);
        co_yield NEG1_even(n - 1, k); // S'(n-1, k, 1).(k-2)

        for (int i = k - 3; i >= 1; i -= 2) {
            co_yield Move(n, i);
            co_yield GEN1_even(n - 1, k); // S(n-1, k, 1).i
            co_yield Move(n, i - 1);
            co_yield NEG1_even(n - 1, k); // S'(n-1, k, 1).(i-1)
        }
    }
}

// S'(n, k, 0) even k
recursive_generator<ret_t> NEG0_even(int n, int k) {
    if (k > 0 && k < n) {
        for (int i = 1; i <= k - 3; i += 2) {
            co_yield GEN1_even(n - 1, k); // S(n-1, k, 1).(i-1)
            co_yield Move(n, i);
            co_yield NEG1_even(n - 1, k); // S'(n-1, k, 1).i
            co_yield Move(n, i + 1);
        }

        co_yield GEN1_even(n - 1, k); // S(n-1, k, 1).(k-2)
        co_yield Move(n, k - 1);
        co_yield NEG1_even(n - 1, k); // S(n-1, k, 1).(k-1)
        co_yield Move(n - 1, 0);
        co_yield NEG0_odd(n - 1, k - 1); // S(n-1, k-1, 1).(k-1)
    }
}

// S(n, k, 1) even k
recursive_generator<ret_t> GEN1_even(int n, int k) {
    if (k > 0 && k < n) {
        co_yield GEN1_odd(n - 1, k - 1);
        co_yield Move(k, k - 1);
        co_yield NEG1_even(n - 1, k);
        co_yield Move(n, k - 2);
        co_yield GEN1_even(n - 1, k);

        for (int i = k - 3; i > 0; i -= 2) {
            co_yield Move(n, i);
            co_yield NEG1_even(n - 1, k);
            co_yield Move(n, i - 1);
            co_yield GEN1_even(n - 1, k);
        }
    }
}

// S'(n, k, 1) even k
recursive_generator<ret_t> NEG1_even(int n, int k) {
    if (k > 0 && k < n) {
        for (int i = 1; i <= k - 3; i += 2) {
            co_yield NEG1_even(n - 1, k);
            co_yield Move(n, i);
            co_yield GEN1_even(n - 1, k);
            co_yield Move(n, i + 1);
        }

        co_yield NEG1_even(n - 1, k);
        co_yield Move(n, k - 1);
        co_yield GEN1_even(n - 1, k);
        co_yield Move(k, 0);
        co_yield NEG1_odd(n - 1, k - 1);
    }
}

// S(n, k, 0) odd k
recursive_generator<ret_t> GEN0_odd(int n, int k) {
    if (k > 1 && k < n) {
        co_yield GEN1_even(n - 1, k - 1);
        co_yield Move(k, k - 1);
        co_yield NEG1_odd(n - 1, k);

        for (int i = k - 2; i > 0; i -= 2) {
            co_yield Move(n, i);
            co_yield GEN1_odd(n - 1, k);
            co_yield Move(n, i - 1);
            co_yield NEG1_odd(n - 1, k);
        }
    }
}

// S'(n, k, 0) odd k
recursive_generator<ret_t> NEG0_odd(int n, int k) {
    if (k > 1 && k < n) {
        for (int i = 1; i <= k - 2; i += 2) {
            co_yield GEN1_odd(n - 1, k);
            co_yield Move(n, i);
            co_yield NEG1_odd(n - 1, k);
            co_yield Move(n, i + 1);
        }

        co_yield GEN1_odd(n - 1, k);
        co_yield Move(k, 0);
        co_yield NEG1_even(n - 1, k - 1);
    }
}

// S(n, k, 1) odd k
recursive_generator<ret_t> GEN1_odd(int n, int k) {
    if (k > 1 && k < n) {
        co_yield GEN0_even(n - 1, k - 1);
        co_yield Move(n - 1, k - 1);
        co_yield GEN1_odd(n - 1, k);

        for (int i = k - 2; i > 0; i -= 2) {
            co_yield Move(n, i);
            co_yield NEG1_odd(n - 1, k);
            co_yield Move(n, i - 1);
            co_yield GEN1_odd(n - 1, k);
        }
    }
}

// S'(n, k, 1) odd k
recursive_generator<ret_t> NEG1_odd(int n, int k) {
    if (k > 1 && k < n) {
        for (int i = 1; i <= k - 2; i += 2) {
            co_yield NEG1_odd(n - 1, k);
            co_yield Move(n, i);
            co_yield GEN1_odd(n - 1, k);
            co_yield Move(n, i + 1);
        }

        co_yield NEG1_odd(n - 1, k);
        co_yield Move(n - 1, 0);
        co_yield NEG0_even(n - 1, k - 1);
    }
}

#endif