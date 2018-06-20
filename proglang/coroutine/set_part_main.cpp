#include <boost/coroutine2/all.hpp>
#include <cctype>
#include <cstdio>
#include <functional>
#include <iostream>

#include "set_partition.hpp"

int main() {
    for (auto i : set_partition_seq(5, 3)) {
        // std::cout << "   Move element " << i;
        std::cout << "   Move element " << std::get<0>(i) << " from block "
                  << std::get<1>(i) << " to " << std::get<2>(i);
        std::cout << std::endl;
    }
    std::cout << "\nDone" << std::endl;
    return EXIT_SUCCESS;
}