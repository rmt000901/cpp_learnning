//
// Created by rmt on 23-3-1.
//

#include <iostream>
#include <cctype>
#include "include/stack.h"

int main()
{
    Stack st;
    char ch;
    unsigned long po;
    std::cout << "Please enter A to add a purchase order,\n"
    << "P to process a PO, or Q to quit.\n";
    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a':
                std::cout << "Enter a PO number to add: ";
                std::cin >> po;
                if (st.isfull())
                    std::cout << "stack already full\n";
                else
                    st.push(po);
                break;
            case 'p':
            case 'P':
                if (st.isempty())
                    std::cout << "stack already empty\n";
                else
                {
                    st.pop(po);
                    std::cout << "PO #" << po << " popped\n";
                }
                break;
        }
        std::cout << "Please enter A to add a purchase order,\n"
                  << "P to process a PO, or Q to quit.\n";
    }
    std::cout << "Bye\n";
    return 0;
}