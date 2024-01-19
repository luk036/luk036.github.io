#ifndef _ELLIPSOID_H
#define _ELLIPSOID_H

#include <cassert>
#include <valarray>

/** For testing propose only */
template <typename _Tp>
class bounding
{
public:
 bounding(_Tp& x, double R)
   : _x(x), _U(x+R), _L(x-R)
    { assert(R > 0); }

  ~bounding() {}

  _Tp calc_error(const _Tp& g) {
    _Tp error = (_U - _L)*g/2;
    if (g > 0) _U = _x;
    else { _L = _x; error = -error; }
    return error;
  }

  void update() { _x = _L + (_U - _L)/2; }

private:
  _Tp& _x;
  _Tp  _U; // upper
  _Tp  _L; // lower
};


/** Enclosing ellipsoid */
template <class Vector>
class ellipsoid
{
  typedef std::valarray<double> Vec;
  typedef std::valarray<Vec> Matrix;

public:
  /** Constructor */
 ellipsoid(Vector& x, double R) :
  _n(x.size()), _Ae(Vec(0., _n), _n), _x(x), _Aeg(_n) {
    assert(R > 0);
    setup();
    for (size_t i=0; i<_n; ++i) {
      _Ae[i][i] = R; // initial radius
    }
  }

  /** Constructor */
 ellipsoid(Vector& x, const Vector& r) :
  _n(x.size()), _Ae(Vec(0., _n), _n), _x(x), _Aeg(_n) {
    setup();
    for (size_t i=0; i<_n; ++i) {
      assert(r[i] > 0);
      _Ae[i][i] = r[i]; // initial radius
    }
  }

  ~ellipsoid() {}

  void setup() {
    _n2 = double(_n)*_n;
    _alpha = _n2 / (_n2 - 1.0);
    _beta = 2.0 /(_n + 1);
  }

  /** Assign Ae*g to Aeg, and then return sqrt(g'*Aeg)) */
  template <class Vec>
  double calc_error(const Vec& g) {
    double dot = 0.;
    for (size_t i=0; i<_n; ++i) {
      _Aeg[i] = 0.;
      for (size_t j=0; j<_n; ++j) {
	       _Aeg[i] += _Ae[i][j] * g[j];
      }
      dot += g[i]*_Aeg[i];
    }
    assert(dot >= 0);
    _error = sqrt(dot);
    return _error;
  }

  void update() {
    for (size_t i=0; i<_n; ++i) {
      _Aeg[i] /= _error; // @todo how to avoid squre root?
      _x[i] -= _Aeg[i]/(_n+1);
    }

    for (size_t i=0; i<_n; ++i) {
      for (size_t j=i; j<_n; ++j) {
        _Ae[i][j] -= _beta*_Aeg[i]*_Aeg[j];
        _Ae[i][j] *= _alpha;
      }
    }

    // Make symmetric
    for (size_t i=0; i<_n-1; ++i) {
      for (size_t j=i+1; j<_n; ++j) {
        _Ae[j][i] = _Ae[i][j];
      }
    }
  }

private:
  size_t  _n;
  Matrix  _Ae;
  Vector& _x;    // center of ellipsoid
  Vec     _Aeg;  // for updating E
  double  _n2;
  double  _alpha;
  double  _beta;
  double  _error;
};


/** @return return status */
enum STATUS {
	FOUND,
	EXCEEDMAXITER,
	NOTFOUND
};


/**
 * -- (Generalized) bisection method for sovling convex minimization problem P:
 *
 *     minimize     fct_0(x)
 *     subject to   fct_j(x) <= 0
 *       where fct_0(x) and fct_j(x)'s are convex
 *
 * Input:
 * 	    E(x)          initial enclosing region
 *      max_it        maximum number of iterations
 *      tol           error tolerance
 *      P             Representation of convex minimization problem
 *
 * Requirement of P:
 *	void		P.assess(x)         assessment of x
 *	bool		P.is_feasible()     return true if x is feasible
 *	double		P.f_value()         returns fct_j(x) if x is infeasible for some j
 *	fct::Vec	P.subgradient()     returns subgradient of fct_0 if x is feasible
 *							                subgradient of fct_j if x is infeasible for some j
 * Requirement of E:
 *
 * output
 *      x             optimal solution
 *      status        FOUND = solution found to tolerance
 *                    EXCEEDMAXITER = no convergence given max_it
 *                    NOTFOUND = no feasible sol'n
 */
//#include <iostream>

template <class Enclosing, class CvxProb, class Domain>
STATUS bisection_algo(Enclosing& E, CvxProb& P, Domain& x, int max_it=1000, double tol=1e-4)
{
  for (int iter = 1; iter <= max_it; ++iter) {
    P.assess(x);
    const double error = E.calc_error(P.subgradient());
    //std::cout << error << "  ";
    if (!P.is_violated()) {
      if (error < tol) return FOUND;
    }
    else {  //  x is infeasible
      if (P.f_value() - error > 0) {
	       return NOTFOUND;   // no feasible sol'n within the given ellipsoid
      }
    }
    E.update();
  }
  return EXCEEDMAXITER;
}

#endif
