//
// Created by rmt on 23-3-13.
//
#include <iostream>
#include "include/dma.h"

int main()
{
    baseDMA shirt("Portbaelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    std::cout << "Displaying baseDMA object:\n";
    std::cout << shirt << std::endl;
    std::cout << "Displaying lacksDMA object:\n";
    std::cout << balloon << std::endl;
    std::cout << "Displaying hasDMA object:\n";
    std::cout << map << std::endl;
    lacksDMA balloon2(balloon);
    std::cout << "Result of lacksDMA copy:\n";
    std::cout << balloon2 << std::endl;
    hasDMA map2;
    map2 = map;
    std::cout << "Result of hasDMA assignment:\n";
    std::cout << map2 << std::endl;
    return 0;
}