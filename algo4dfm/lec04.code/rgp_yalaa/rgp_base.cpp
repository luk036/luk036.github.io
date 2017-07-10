#include "rgp_base.h"
#include <map>

typedef yalaa::details::double_iv_t iv_t;
typedef yalaa::traits::interval_traits<iv_t> iv_traits;
typedef yalaa::aff_e_d aaf;
typedef std::map<typename aaf::error_t, int> pmap;

template <typename AF>
typename AF::base_t max(const AF& af, pmap &pol)
{
  typename AF::ac_t ac(af.ac());
  typename AF::base_t res = ac.central(); 
  for(auto it(ac.begin()); it != ac.end(); ++it) {
    if (it->dev() > 0) {
      pol[*it] = 1;
      res += it->dev();
    }
    else if (it->dev() < 0) {
      pol[*it] = -1;
      res -= it->dev();
    }
    else {
      pol[*it] = 0;
    }
  }
  return res;
}

template <typename AF>
typename AF::base_t eval(const AF &af, const pmap &pol)
{
  typename AF::ac_t ac(af.ac());
  typename AF::base_t res = ac.central(); 
  for(auto it(ac.begin()); it != ac.end(); ++it) {
    pmap::const_iterator pit(pol.find(*it));
    if(pit == pol.end()) throw; // Noise symbol is not in the map
    res += it->dev() * pit->second;
  }
  return res;
}

/** Constructor (for aaf -> double) */
template <> template <>
monomial<double>::monomial(const monomial<aaf>& mon, 
			const pmap& polarity)
  : _a(mon._a.size()), _b(eval(mon._b, polarity))
{
  for (size_t i=0; i<_a.size(); ++i) {
    _a[i] = eval(mon._a[i], polarity);
  }
}

template <class Arr>
void rgp_base::assess(const Arr& x)
{ 
  for (size_t i= 1; i<_M.size(); ++i) {
    pmap polarity;
    _f_value = max(_M[i](x), polarity);
    if (_f_value > 0) {
      posynomial<double> P(_M[i], polarity);
      _subgradient = P.log_exp_gradient(x);
      _is_violated = true;
      return;
    }
  }
  
  _is_violated = false;
  pmap polarity;
  _f_value = max(_M[0](x), polarity);
  posynomial<double> P(_M[0], polarity);
  //_f_value = _M[0].fvalue_with_gradient(x, _subgradient);
  _subgradient = P.log_exp_gradient(x);
}

template
void rgp_base::assess(const std::valarray<double>& x);
