//
// Created by rmt on 23-3-1.
//
#include <iostream>
#include "include/stack.h"
Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        std::cout << "top= " << top << std::endl;
        item = items[--top];
        return true;
    }
    else
        return false;
}