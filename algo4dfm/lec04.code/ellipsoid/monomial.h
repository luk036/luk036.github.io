#ifndef _MONOMIAL_HPP
#define _MONOMIAL_HPP

#include <valarray>
#include <cassert>

/**
 * Reference:
 *  S.P. Boyd, S.-J. Kim and L.Vandenberghe and A. Hassibi.
 *  A Tutorial on Geometric Programming. Available at
 *  http://www.standford.edu/~boyd/gp_tutorial.html
 */

/**
 * Monomial function object. Let $x_1$, ..., $x_n$ denote $n$ real
 * positive variable and x = ($x_1$, ..., $x_n$) a vector with
 * components $x_i$. A read valued function f of x, with the form
 *
 *    f(x0, ..., xn-1) = c * x0^a1 * x2^a2 ... xn-1^an-1
 *
 * where $c$ > 0 and $a_i \in R$, is called a monomial function, or
 * more informally, a monomial (of the variables $x_1$, ..., $x_n$).
 * We refer to the constant $c$ as the coefficient of the monmial,
 * and we refer to the constants $a_1$, ... $a_n$ as the exponents of
 * the monomial. As an example, $2.3 x_1^2 x_2^{-0.15}$ is a monomial
 * of the variables $x_1$ and $x_2$, with coefficient 2.3 and
 * $x_2$-exponent -0.15.
 * Any positive constant is a monomial, as is any variable. Monomials
 * are closed under multiplication and division: if $f$ and $g$ are
 * both monomials then so are $f*g$ and $f/g$. (This includes scaling
 * by any positive constant.) A monomial raise to any power is also a
 * monomial.
 *
 * The term `monomial', as used here (in the context of geometric
 * programming) is similar to, but differs from the standard
 * definition of `monomial' used in algebra. In algebra, a monomial
 * has the form about, but the exponents $a_i$ must be nonnegative
 * integers, and the coefficent $c$ is one.
 *
 * @todo: In current implementation, the exponent _a is represented by
 *only <double>. The type should be _Tp in general such that it can be also
 *be a <AAF>.
 */
template <typename _Tp>
class monomial
{
  typedef std::valarray<_Tp>  Vec;
  typedef monomial<_Tp> _Self;

public:
  /** Constructor */
  explicit monomial(size_t n) : _a(_Tp(0), n), _b(_Tp(0)) {}

  /** Constructor */
  monomial(size_t n, const _Tp& c) : _a(_Tp(0), n), _b(log(c)) {}

  /** Constructor (for AAF -> double) */
  template <typename _Up, class Map>
  monomial(const monomial<_Up>& mon, const Map& polarity);

  monomial(size_t n, const _Tp ar[]) : _a(_Tp(0), n), _b(log(ar[0]))
  { for (size_t i=1; i<=n; ++i) _a[i-1] = ar[i]; }

  /** Destructor */
  ~monomial() {}

  /** Multiply and assign */
  _Self& operator*=(const _Self& M)
  { _a += M._a; _b += M._b; return *this; }

  /** Divide and assign */
  _Self& operator/=(const _Self& M)
  { _a -= M._a; _b -= M._b; return *this; }

  /** Multiply and assign */
  _Self& operator*=(const _Tp& c)
  { _b += log(c); return *this; }

  /** Divide and assign */
  _Self& operator/=(const _Tp& c)
  { _b -= log(c); return *this; }

  /** Multiply */
  _Self operator*(const _Self& m) const { return _Self(*this) *= m; }

  /** Divided */
  _Self operator/(const _Self& m) const { return _Self(*this) /= m; }

  /** Multiply */
  _Self operator*(const _Tp& c) const { return _Self(*this) *= c; }

  /** Divide */
  _Self operator/(const _Tp& c) const { return _Self(*this) /= c; }

  /** Square root */
  void sqrt() { _a /= 2.; _b /= 2.; }

  /** Function evaluation of log(f(exp(y))), i.e., res = b + dot(a,y). */
  template <typename _Up>
  _Tp operator()(const _Up& y) const
  {
    assert(_a.size() == y.size());
    _Tp res = _b;
    for (size_t i=0; i<_a.size(); ++i) {
      //if (_a[i] == 0) continue;
      res += _a[i] * y[i];
    }
    return res;
  }

  /** Gradient of log(f(exp(y))) */
  template <typename _Up>
  Vec gradient(const _Up& ) const { return _a; }

  /** Function evaluation and gradient of log(f(exp(y)) */
  template <typename _Up>
  _Tp log_exp_fvalue_with_gradient(const _Up& y, Vec& g) const
  {
    assert(_a.size() == y.size());
    _Tp res = _b;
    for (size_t i=0; i<_a.size(); ++i) {
      if (_a[i] == 0) continue;
      res += _a[i] * y[i];
    }
    g = _a; // gradient
    return res;
  }

  void set_coeff(_Tp c)
  {
    //assert(c > 0);
    _b = log(c);
  }

public:
  Vec _a;    /**< vector of exponents (a0, .. an-1)  */
  _Tp _b;    /**< coefficient in log, i.e. log(c)  */
};


// Non-member functions

/** Square root */
template <typename _Tp>
inline monomial<_Tp> sqrt(monomial<_Tp> m)
{ m.sqrt(); return m; }


/** Division */
template <typename _Tp, typename _Up>
inline monomial<_Tp> operator/(const _Up& c, const monomial<_Tp>& m)
{
  return monomial<_Tp>(m._a.size(), _Tp(c)) / m;
}

/** Multiplication */
template <typename _Tp, typename _Up>
inline monomial<_Tp> operator*(const _Up& c, const monomial<_Tp>& m)
{
  return m * _Tp(c); // assume commutative
}

#endif
