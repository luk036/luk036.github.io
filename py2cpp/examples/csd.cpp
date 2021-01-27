#include <iostream>
#include <string>
#include <cmath> // ceil, fabs, log
#include <string_view>

using std::ceil;
using std::fabs;
using std::log2;
using std::pow;
using std::string;

auto to_csd(double num, int places=0) -> string {
	if (num == 0.) return "0";
	auto absnum = fabs(num);
	auto n = absnum < 1. ? 0 : int(ceil(log2(absnum * 1.5)));
	auto csd_str = string{absnum < 1. ? "0" : ""};
	auto limit = pow(2., n) / 3.;
	while (n > -places) {
		if (n == 0) csd_str += '.';
		n -= 1;
		if (num > limit) {
		    csd_str += '+';
		    num -= 1.5 * limit;
		}
		else if (num < -limit) {
		    csd_str += '-';
		    num += 1.5 * limit;
		}
		else csd_str += '0';
		limit /= 2.;
	}
	return csd_str;
}


/** Convert the CSD string to a decimal */
auto to_decimal(std::string_view csd_str) -> double
{
    auto num = 0.0;
    auto loc = 0;
	auto i = 0;
    for (auto c : csd_str) {
		switch (c) {
        case '+':
            num *= 2.; num += 1.; break;
        case '-':
            num *= 2.; num -= 1.; break;
        case '0':
            num *= 2.; break;
        case '.':  // unlikely
            loc = i + 1;
		}
		++i;
	}            
    if (loc != 0)
        num /= std::pow(2, csd_str.size() - loc);
    return num;
}

double to_decimal_old(std::string csd_str){
	std::string left = "";
	std::string right = "";
	for(size_t i = 0;i<csd_str.size();i++){
		if(csd_str[i]=='.'){
			right = csd_str.substr(i+1);
			break;
		}
		else
			left += csd_str[i];
	}
   //std::cout << "left is:" << left << std::endl;
   //std::cout << "right is:" << right << std::endl;   
   int msb_power = left.size()-1;
   double num = 0.0;
   for(size_t i = 0;i<csd_str.size();i++){
	   double power_of_two = pow(2.0,(msb_power-(signed int)(i)));
	   if(csd_str[i] == '+')
		   num += power_of_two;
	   else if(csd_str[i] == '-')
		   num -= power_of_two;
	   //std::cout << "now msb_power-i is:" << msb_power-(signed int)(i) << std::endl;
   }
   std::cout << "num is :" << num << std::endl;
   return num;
}

auto to_csdfixed(double num, unsigned int nnz=4) -> string {
	if (num == 0.) return "0";
	auto an = fabs(num);
	auto n = an < 1. ? 0 : int(ceil(log2(an * 1.5)));
	auto csd_str = string{an < 1. ? "0" : ""};
    auto limit = pow(2., n) / 3.;
	while (n > 0 || nnz > 0) {
		if (n == 0) csd_str += '.';
		n -= 1;
		if (num > limit) {
			csd_str += '+';
			num -= 1.5 * limit;
			nnz -= 1;
		}
		else if (num < -limit) {
			csd_str += '-';
			num += 1.5 * limit;
			nnz -= 1;
		}
		else csd_str += '0';
		limit /= 2.;

		if (nnz == 0)
			num = 0;
	}
	return csd_str;
}
    

	
int main(void){
	std::string str1;
	double num1;
	str1 = to_csd(16.5);
	num1 = to_decimal("+0000.0+");
	return 0;
}
