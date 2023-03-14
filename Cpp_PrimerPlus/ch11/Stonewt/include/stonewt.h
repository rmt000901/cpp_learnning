//
// Created by rmt on 23-3-5.
//

#ifndef STONEWT_STONEWT_H
#define STONEWT_STONEWT_H
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    operator int() const;
    operator double() const;
};
#endif //STONEWT_STONEWT_H
