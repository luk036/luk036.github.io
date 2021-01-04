// #include <fmt/core.h>
#include <range/v3/all.hpp> // get everything
#include <ranges>

class base
{
public:
        int _a;
	base(int a) : _a(a) {}
};

class derived : public base
{
public:
	void foo() { base::_a = 3; }
};

int main()
{
	auto d = derived{6};
	d.foo();
        // fmt::print("{}\n", d._a );
	return 0;
}
