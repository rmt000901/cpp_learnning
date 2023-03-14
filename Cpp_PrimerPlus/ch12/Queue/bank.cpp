//
// Created by rmt on 23-3-9.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    std::srand(std::time(0));

    std::cout << "Case Study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maximum size of queue: ";
    int qs;
    std::cin >> qs;
    Queue line(qs);

    std::cout << "Enter the number of simulation hours: ";
    int hours;
    std::cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    std::cout << "Enter the average number of customers per hour: ";
    double perhour;
    std::cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    if (customers > 0)
    {
        std::cout << "customers accepted: " << customers << std::endl;
        std::cout << " customers served: " << served << std::endl;
        std::cout << "        turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << (double) sum_line / cyclelimit << std::endl;
        std::cout << " average wait time: " << (double) line_wait / served << " minutes\n";
    }
    else
        std::cout << "No customers!\n";
    std::cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}