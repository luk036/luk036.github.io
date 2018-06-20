#include <iostream>
#include "set_partition20.hpp"

int main() 
{
    int n=5, k=3;
    int b[100+1];  /* maximum value of n */
    int cnt=1;
    int i=1, j=0;
    for (; i<=n-k; ++i) b[i] = 0;
    for (; i<=n; ++i, ++j) b[i] = j;

    for ( auto [x,y] : set_partition(5,3)) {
        ++cnt;
        int old = b[x];
        b[x] = y;
        std::cout << " Move element " << x 
                  << " from block " << old 
                  << " to block " << y << '\n';
    }
    assert(stirling2nd(n, k) == cnt);
    std::cout << "\nDone" << std::endl;
    return EXIT_SUCCESS;
}