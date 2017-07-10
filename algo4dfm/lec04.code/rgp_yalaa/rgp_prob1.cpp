#include "rgp_prob1.h"
#include <yalaa.hpp>

typedef yalaa::details::double_iv_t iv_t;
typedef yalaa::traits::interval_traits<iv_t> iv_traits;
typedef yalaa::aff_e_d aaf;

static const aaf
  Awall(100),	 // area of wall
  Aflr(iv_t(8.0,12)),  // area of floor
  alpha(0.8),		// lowest aspect ratio
  beta(1.25),		// highest aspect ratio
  gamma2(0.8),        // lowest aspect ratio
  delta(1.25)         // highest aspect ratio
  ;

enum vars {
  h,	// height
  w,	// weight
  d,	// depth
  NUM_VARS
};


rgpprob1::rgpprob1() : rgp_base(NUM_VARS)
{
  // Objective function: h^-1 w^-1 d^-1 (inverse of volume)
  { monomial<aaf> obj(NUM_VARS);
    obj._a[h] = aaf(-1.0); obj._a[w] = aaf(-1.0); obj._a[d] = aaf(-1.0);
    obj.set_coeff(aaf(1.0));
    rgp_base::_M.push_back( posynomial<aaf>(obj) ); }
  
  // (2/Awall)hw + (2/Awall)hd <= 1
  { monomial<aaf> T11(NUM_VARS);
    T11._a[h] = aaf(1.0); T11._a[w] = aaf(1.0);
    T11.set_coeff(2./Awall);
    monomial<aaf> T12(NUM_VARS);
    T12._a[h] = aaf(1.0); T12._a[d] = aaf(1.0);
    T12.set_coeff(2./Awall);
    posynomial<aaf> P1(T11);
    P1 += T12; 
    rgp_base::_M.push_back(P1); }
  
  { monomial<aaf> T2(NUM_VARS);
    T2._a[w] = aaf(1.0); T2._a[d] = aaf(1.0);
    T2.set_coeff(1./Aflr);
    rgp_base::_M.push_back( posynomial<aaf>(T2) ); }
  
  { monomial<aaf> T3(NUM_VARS);
    T3._a[h] = aaf(-1.0); T3._a[w] = aaf(1.0);
    T3.set_coeff(alpha);
    rgp_base::_M.push_back( posynomial<aaf>(T3) ); }
  
  { monomial<aaf> T4(NUM_VARS);
    T4._a[h] = aaf(1.0); T4._a[w] = aaf(-1.0);
    T4.set_coeff(1./beta);
    rgp_base::_M.push_back( posynomial<aaf>(T4) ); }
  
  { monomial<aaf> T5(NUM_VARS);
    T5._a[w] = aaf(1.0); T5._a[d] = aaf(-1.0);
    T5.set_coeff(gamma2);
    rgp_base::_M.push_back( posynomial<aaf>(T5) ); }
  
  { monomial<aaf> T6(NUM_VARS);
    T6._a[w] = aaf(-1.0); T6._a[d] = aaf(1.0);
    T6.set_coeff(1./delta);
    rgp_base::_M.push_back( posynomial<aaf>(T6) ); }
}

