#ifndef CO2_SET_PARTITION
#define CO2_SET_PARTITION 1

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
#include <cctype>
#include <cstdio>
#include <functional>
#include <cassert>
#include <utility>

#include <boost/coroutine2/all.hpp>

// Stirling number of second kind. Note that this function is for
// testing purpose only and is slow because of reducdant calculation.
constexpr int stirling2nd(int n, int k)
{
  if (k >= n || k <= 1) return 1;
  return stirling2nd(n-1, k-1) + k * stirling2nd(n-1, k);
}


class set_partition {
  typedef std::tuple<int,int,int> ret_t;
  typedef std::function<void(ret_t)> Fun;

private:
  int n;
  int k;
  int b[100+1];  /* maximum value of n */
  int cnt;
  Fun cb;

public:
  set_partition(int n_, int k_, Fun cb_)
    : n(n_), k(k_), cnt(0), cb(cb_) {
    // Initial partition
    int i=1, j=0;
    for (; i<=n-k; ++i) b[i] = 0;
    for (; i<=n; ++i, ++j) b[i] = j;
  }

  ~set_partition() {
    assert(stirling2nd(n, k) == cnt);
  }

  void run() {
    ++cnt;
    if (k%2==0) GEN0_even( n, k );
    else GEN0_odd( n, k);
  }

  void Move ( int x, int y ) 
  {
    ++cnt;
    int old = b[x];
    b[x] = y;
    assert(old != y);
    cb(std::make_tuple(x,old,y));
  }


private:
  void GEN0_even ( int n, int k );  // S(n,k,0) even k
  void NEG0_even ( int n, int k );  // S'(n,k,0) even k
  void GEN1_even ( int n, int k );  // S(n,k,1) even k
  void NEG1_even ( int n, int k );  // S'(n,k,1) even k
  void GEN0_odd ( int n, int k );   // S(n,k,0) odd k
  void NEG0_odd ( int n, int k );   // S'(n,k,0) odd k
  void GEN1_odd ( int n, int k );   // S(n,k,1) odd k
  void NEG1_odd ( int n, int k );   // S'(n,k,1) odd k

};

// The lists S(n,k,0) and S(n,k,1) satisfy the following properties.
// 1. Successive RG sequences differ in exactly one position.
// 2. first(S(n,k,0)) = first(S(n,k,1)) = 0^{n-k}0123...(k-1)
// 3. last(S(n,k,0)) = 0^{n-k}12...(k-1)0
// 4. last(S(n,k,1)) = 012...(k-1)0^{n-k}
// Note that first(S'(n,k,p)) = last(S(n,k,p))

// S(n,k,0) even k
void set_partition::GEN0_even ( int n, int k ) 
{
  if (!(k > 0 && k < n)) return;

  GEN0_odd(n-1, k-1);    // S(n-1, k-1, 0).(k-1)
  Move(n-1,k-1);
  GEN1_even(n-1, k);     // S(n-1, k, 1).(k-1)
  Move(n, k-2);
  NEG1_even(n-1, k);     // S'(n-1, k, 1).(k-2)  

  for (int i=k-3; i>=1; i-=2) {
    Move(n, i);
    GEN1_even(n-1, k);   // S(n-1, k, 1).i
    Move(n, i-1);
    NEG1_even(n-1, k);   // S'(n-1, k, 1).(i-1)
  }
}


// S'(n, k, 0) even k
void set_partition::NEG0_even ( int n, int k ) 
{
  if (!(k > 0 && k < n)) return;

  for (int i=1; i<=k-3; i+=2) {
    GEN1_even(n-1, k);   // S(n-1, k, 1).(i-1)
    Move(n, i);      
    NEG1_even(n-1, k);   // S'(n-1, k, 1).i
    Move(n, i+1);
  }

  GEN1_even(n-1, k);     // S(n-1, k, 1).(k-2)
  Move(n, k-1);
  NEG1_even(n-1, k);     // S(n-1, k, 1).(k-1)
  Move(n-1, 0);      
  NEG0_odd(n-1, k-1);    // S(n-1, k-1, 1).(k-1)
}


// S(n, k, 1) even k
void set_partition::GEN1_even ( int n, int k ) 
{
  if (!(k > 0 && k < n)) return;

  GEN1_odd(n-1, k-1);
  Move(k, k-1);
  NEG1_even(n-1, k);
  Move(n, k-2);
  GEN1_even(n-1, k);

  for (int i=k-3; i>0; i-=2) {
    Move(n, i);
    NEG1_even(n-1, k);
    Move(n, i-1);
    GEN1_even(n-1, k);
  }
}


// S'(n, k, 1) even k
void set_partition::NEG1_even ( int n, int k ) 
{
  if (!(k > 0 && k < n)) return;

  for (int i=1; i<=k-3; i+=2) {
    NEG1_even(n-1, k);
    Move(n, i);
    GEN1_even(n-1, k);
    Move(n, i+1);
  }

  NEG1_even(n-1, k);
  Move(n, k-1);
  GEN1_even(n-1, k);
  Move(k, 0);
  NEG1_odd(n-1, k-1);
}


// S(n, k, 0) odd k
void set_partition::GEN0_odd ( int n, int k ) 
{
  if (!(k > 1 && k < n)) return;

  GEN1_even(n-1, k-1);
  Move(k, k-1);
  NEG1_odd(n-1, k);

  for (int i=k-2; i>0; i-=2) {
    Move(n, i);
    GEN1_odd(n-1, k);
    Move(n, i-1);
    NEG1_odd(n-1, k);
  }
}


// S'(n, k, 0) odd k
void set_partition::NEG0_odd ( int n, int k ) 
{
  if (!(k > 1 && k < n)) return;

  for (int i=1; i<=k-2; i+=2) {
    GEN1_odd(n-1, k);
    Move(n, i);
    NEG1_odd(n-1, k);
    Move(n, i+1);
  }

  GEN1_odd(n-1, k);
  Move(k, 0);
  NEG1_even(n-1, k-1);
}


// S(n, k, 1) odd k
void set_partition::GEN1_odd ( int n, int k ) 
{
  if (!(k > 1 && k < n)) return;

  GEN0_even(n-1, k-1);
  Move(n-1, k-1);
  GEN1_odd(n-1, k);

  for (int i=k-2; i>0; i-=2) {
    Move(n, i);
    NEG1_odd(n-1, k);
    Move(n, i-1);
    GEN1_odd(n-1, k);
  }
}


// S'(n, k, 1) odd k
void set_partition::NEG1_odd ( int n, int k ) 
{
  if (!(k > 1 && k < n)) return;

  for (int i=1; i<=k-2; i+=2) {
    NEG1_odd(n-1, k);
    Move(n, i);
    GEN1_odd(n-1, k);
    Move(n, i+1);
  }

  NEG1_odd(n-1, k);
  Move(n-1, 0);
  NEG0_even(n-1, k-1);
}


typedef std::tuple<int,int,int> ret_t;
typedef boost::coroutines2::coroutine< ret_t > coro_t;

  coro_t::pull_type set_partition_seq(int n, int k) {
    return
      coro_t::pull_type(
        [n,k]( coro_t::push_type & yield) {
            set_partition p(n,k,[&yield](ret_t ch){
              yield(ch);
            });
            p.run();
      }) ;

  }

#endif