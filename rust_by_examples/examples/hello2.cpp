// file: hello2.cpp
// Compile with:
// $ g++ hello2.cpp -o hello2

#include <stdio.h>  // for printf
#include <cmath>    // for std::sin()

int main() {
    auto a = 12 + 4; // C++11
    printf("The ans is %d.\n", a); // %d for int

    auto b = std::sin(0.4);
    printf("The ans is %f.\n", b); // %f for double
}
