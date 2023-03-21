//
// Created by rmt on 23-3-21.
//
#include <iostream>
#include <string>
#include "include/queuetp.h"

int main()
{
    QueueTP<std::string> cs(5);
    std::string temp;

    while (!cs.isfull())
    {
        std::cout << "Please enter your name. You will be "
                     "served in the order of arrival.\n"
                     "name: ";
        getline(std::cin, temp);
        cs.enqueue(temp);
    }
    std::cout << "The queue is full. Processing begins!\n";

    while (!cs.isempty())
    {
        cs.dequeue(temp);
        std::cout << "Now processing " << temp << "...\n";
    }
    return 0;
}