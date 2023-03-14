//
// Created by rmt on 23-3-5.
//
#include <iostream>
#include "include/stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    std::cout << "Convert to double => ";
    std::cout << "Poppins: " << p_wt << " pounds.\n";
    std::cout << "Convert to int => ";
    std::cout << "Poppins: " << int(poppins) << " pounds.\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Wow! ";
        st.show_stn();
    }
}