#include "gp_prob1.h"
#include "posynomial.h"

static const double
  Awall = 100.0,		// area of wall
  Aflr  = 10.0,		// area of floor
  alpha = 0.8,		// lowest aspect ratio
  beta  = 1.25,		// highest aspect ratio
  gamma2 = 0.8,        // lowest aspect ratio
  delta = 1.25         // highest aspect ratio
  ;

enum vars {
  h,	// height
  w,	// weight
  d,	// depth
  NUM_VARS
};

gpprob1::gpprob1() : gp_base(NUM_VARS)
{
  // Objective function: h^-1 w^-1 d^-1 (inverse of volume)
  { const double ar[] = {1.0, -1, -1, -1};	
    monomial<double> obj(NUM_VARS, ar);
    //obj._a[h] = -1; obj._a[w] = -1; obj._a[d] = -1;
    //obj.set_coeff(1.0);
    gp_base::_M.push_back( posynomial<double>(obj) ); }
  
  // (2/Awall)hw + (2/Awall)hd <= 1
  { monomial<double> T11(NUM_VARS);
    T11._a[h] = 1; T11._a[w] = 1;
    T11.set_coeff(2./Awall);
    monomial<double> T12(NUM_VARS);
    T12._a[h] = 1; T12._a[d] = 1;
    T12.set_coeff(2./Awall);
    posynomial<double> P1(T11);
    P1 += T12; 
    gp_base::_M.push_back(P1); }
	
  { monomial<double> T2(NUM_VARS);
    T2._a[w] = 1; T2._a[d] = 1;
    T2.set_coeff(1./Aflr);
    gp_base::_M.push_back( posynomial<double>(T2) ); }
  
  { monomial<double> T3(NUM_VARS);
    T3._a[h] = -1; T3._a[w] = 1;
    T3.set_coeff(alpha);
    gp_base::_M.push_back( posynomial<double>(T3) ); }
  
  { monomial<double> T4(NUM_VARS);
    T4._a[h] = 1; T4._a[w] = -1;
    T4.set_coeff(1./beta);
    gp_base::_M.push_back( posynomial<double>(T4) ); }

  { monomial<double> T5(NUM_VARS);
    T5._a[w] = 1; T5._a[d] = -1;
    T5.set_coeff(gamma2);
    gp_base::_M.push_back( posynomial<double>(T5) ); }
  
  { monomial<double> T6(NUM_VARS);
    T6._a[w] = -1; T6._a[d] = 1;
    T6.set_coeff(1./delta);
    gp_base::_M.push_back( posynomial<double>(T6) ); }
}
