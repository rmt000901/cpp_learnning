//
// Created by rmt on 23-3-6.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/strngbad.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    String name;
    std::cout << "Hi, what's your name?\n>> ";
    std::cin >> name;
    std::cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        std::cout << i+1 << ": ";
        std::cin.get(temp, MaxLen);
        while (std::cin && std::cin.get() != '\n')
            continue;
        if (!std::cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;

    if (total > 0)
    {
        std::cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            std::cout << sayings[i][0] << ": " << sayings[i] << std::endl;

        /*int shortest = 0;
        int first = 0;
        for (i = 0; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        std::cout << "Shortest saying:\n" << sayings[shortest] << std::endl;
        std::cout << "First alphbetically:\n" << sayings[first] << std::endl;
        std::cout << "This program used " << String::HowMany() << " String object. Bye.\n";*/

        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        std::cout << "Shortest saying:\n" << * shortest << std::endl;
        std::cout << "First alphabetically:\n" << * first << std::endl;
        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        std::cout << "My favorite saying:\n" << *favorite << std::endl;
        delete favorite;
    }
    else
        std::cout << "No input! Bye.\n";
    return 0;
}
