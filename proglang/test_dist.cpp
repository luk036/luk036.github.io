#include <numeric>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


template <class Cont, class BinaryOperation>
auto dot(const Cont& a, const Cont& b, BinaryOperation op)
  -> decltype(op(*A.begin(), *B.begin()))
{
    using T = decltype( op(*A.begin(), *B.begin()) );
    return std::inner_product(std::begin(a), std::end(a),
    	std::begin(b), T(0), std::plus<T>(), op);
}

template <class Cont, class U, class BinaryOperation>
auto dH(U a, const Cont& B, BinaryOperation op)
  -> decltype(op(a, *B.begin()))
{
    auto cmp = [a,op](U b1, U b2)-> bool { return op(a, b1) < op(a, b2); };
    auto it = std::min_element(std::begin(B), std::end(B), cmp);
    return op(a, *it);
}

template <class Cont, class BinaryOperation>
auto dH(const Cont& A, const Cont& B, BinaryOperation op)
  -> decltype(op(*A.begin(), *B.begin()))
{
    using T = decltype( op(*A.begin(), *B.begin()) );
    using U = typename Cont::value_type;
    std::vector<T> H(A.size());
    auto calcD = [B,op](U a)-> T { return dH(a, B, op); };
    std::transform(std::begin(A), std::end(A), std::begin(H), calcD);
    return *std::max_element(std::begin(H), std::end(H));
}

template <class Cont, class BinaryOperation>
auto Hausdorff(const Cont& A, const Cont& B, BinaryOperation op)
  -> decltype(op(*A.begin(),*B.begin()))
{
    return std::max(dH(A,B,op), dH(B,A,op));
}


int main()
{
    std::vector<int> va{0, 1, 2, 3, 4};
    std::vector<int> vb{5, 4, 2, 3, 1};

    auto hamming = [](int a, int b)-> int { return a == b? 0:1; };
    int r1 = dot(va, vb, 0, hamming);
    std::cout << "Number of pairwise matches between a and b: " <<  r2 << '\n';

    auto affine = [](int a, int b) -> int { return abs(a - b); };
    int r2 = Hausdorff(va, vb, affine);
    std::cout << "Hausforff distance of a and b: " << r1 << '\n';

}
