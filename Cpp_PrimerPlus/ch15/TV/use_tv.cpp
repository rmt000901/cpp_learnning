//
// Created by rmt on 23-3-20.
//
#include <iostream>
#include "include/tv.h"

int main()
{
    Tv s42;
    std::cout << "Initial settings for 42\" TV:\n";
    s42.setting();
    s42.onoff();
    s42.chanup();
    std::cout << "\nAdjusted settings for 42\" TV:\n";
    s42.chanup();
    std::cout << "\nAdjusted setting for 42\" TV:\n";
    s42.setting();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    std::cout << "\n42\" settings after using remote:\n";
    s42.setting();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << "\n58\" settings:\n";
    s58.setting();
    return 0;
}