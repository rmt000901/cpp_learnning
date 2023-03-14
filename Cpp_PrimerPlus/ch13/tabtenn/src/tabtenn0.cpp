//
// Created by rmt on 23-3-9.
//
#include <iostream>
#include "../include/tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const std::string &fn, const std::string &ln, bool ht)
                : firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname << std::endl;
}

RatedPlayer::RatedPlayer(unsigned int r, const std::string &fn, const std::string &ln, bool ht)
: TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
: TableTennisPlayer(tp), rating(r)
{
}