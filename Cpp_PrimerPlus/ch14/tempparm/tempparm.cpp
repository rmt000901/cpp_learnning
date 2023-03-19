//
// Created by rmt on 23-3-18.
//
#include <iostream>
#include "include/stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() {};
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};

int main()
{
    Crab<Stack> nebula;
    int ni;
    double nb;
    std::cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (std::cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }
    while (nebula.pop(ni, nb))
        std::cout << ni << ", " << nb << std::endl;
    std::cout << "Done.\n";

    return 0;
}