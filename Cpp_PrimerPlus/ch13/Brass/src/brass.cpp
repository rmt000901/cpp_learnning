//
// Created by rmt on 23-3-10.
//
#include <iostream>
#include "../include/brass.h"

AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        std::cout << "Negative deposit not allowed; "
        << "deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = std::cout.precision(2);
    return f;
}

void AcctABC::Restore(AcctABC::Formatting &f) const
{
    std::cout.setf(f.flag, std::ios_base::floatfield);
    std::cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
    if (amt < 0)
        std::cout << "Withdrawal amount must be positive; "
        << "withdrawal canceled.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        std::cout << "Withdrawal amount of $" << amt
        << " exceeds your balance.\n"
        << "Withdrawal canceled.\n";
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    std::cout << "Brass Client: " << FullName() << std::endl;
    std::cout << "Account Number: " << AcctNum() << std::endl;
    std::cout << "Balance: $" << Balance() << std::endl;
    Restore(f);
}

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r)
: AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
: AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    std::cout << "BrassPlus Client: " << FullName() << std::endl;
    std::cout << "Account Number: " << AcctNum() << std::endl;
    std::cout << "Balance: $" << Balance() << std::endl;
    std::cout << "Maximum loan: $" << maxLoan << std::endl;
    std::cout << "Owed to bank: $" << owesBank << std::endl;
    std::cout.precision(3);
    std::cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << std::endl;
        std::cout << "Finance charge: $" << advance * rate << std::endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        std::cout << "Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}
