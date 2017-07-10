#include "rgp_prob1.h"
#include <ellipsoid.h>
#include <iostream>

int main()
{
  typedef std::valarray<double> Vec;
  
  rgpprob1 P;
  const size_t NUM_VARS = 3;
  
  // Initial x
  Vec x(NUM_VARS);
  x[0] = x[1] = x[2] = 0; // log(1)
  
  ellipsoid<Vec> E(x, log(200));
  STATUS status = bisection_algo(E, P, x, 1000, 1e-4);
  if (status == FOUND) {
    std::cout << "optimal volume = " << exp(x[0]+x[1]+x[2]) << std::endl;
  }
  
  return 0;
}
