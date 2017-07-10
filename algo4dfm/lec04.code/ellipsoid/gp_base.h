#ifndef GP_BASE_H
#define GP_BASE_H

#include "posynomial.h"
#include <valarray>
#include <vector>

class gp_base
{
  typedef std::valarray<double> Vec;

public:
  gp_base(size_t n) : _gradient(n) {}
  ~gp_base() {}
  
  bool is_violated() const { return _is_violated; }
  double f_value() const { return _f_value; }
  const Vec& subgradient() const { return _gradient; }
  
  template <class Arr>
  void assess(const Arr& x) 
  {
    for (size_t i= 1; i<_M.size(); ++i) {
      _f_value = _M[i].log_exp_fvalue_with_gradient(x, _gradient);
      if (_f_value > 0) {
	_is_violated = true;
	return;
      }
    }
    _is_violated = false;
    //_f_value = _M[0].fvalue_with_gradient(x, _gradient);
    _gradient = _M[0].log_exp_gradient(x);
  }
  
private:
  double _f_value;
  Vec	 _gradient;
  bool   _is_violated;
  
protected:
  std::vector<posynomial<double> > _M; 
};

#endif 
