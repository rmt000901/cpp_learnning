//
// Created by rmt on 23-3-1.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};
#endif //STACK_STACK_H
