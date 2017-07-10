#include "ellipsoid.h"
#include <iostream>

/** 
  Problem 3: 
  min  0.5*((x-0.1)^2
  s.t. x + 3 <= 0
*/
class Prob3
{
public:
  Prob3() {}
  ~Prob3() {}
  
  void assess(double x)
  {
    double f_value = x + 3;
    if (f_value > 0) {
      _f_value = f_value;
      _gradient = 1; 
      _is_violated = true;
      return;
    }
    
    _gradient = x - 0.1; 
    _is_violated = false;
  }

  bool is_violated() const { return _is_violated; }
  double f_value() const { return _f_value; }
  double subgradient() const { return _gradient; }

private:
  double _f_value;
  double _gradient;
  bool   _is_violated;
};



int main()
{
  Prob3 P;
  
  // Initial x
  double x = 0;
  
  // Initial enclosing interval
  bounding<double> I(x, 20);
  
  STATUS status = bisection_algo(I, P, x, 1000, 1e-4);
  if (status == FOUND) {
    std::cout <<  x  << std::endl;
  }
  
  return 0;
}
