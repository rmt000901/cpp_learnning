//
// Created by rmt on 23-3-6.
//
#include <iostream>
#ifndef STRINGBAD_STRNGBAD_H
#define STRINGBAD_STRNGBAD_H

class String
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length () const {return len;}
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
    static int HowMany();

    static const int CINLIM = 80;
};
#endif //STRINGBAD_STRNGBAD_H
