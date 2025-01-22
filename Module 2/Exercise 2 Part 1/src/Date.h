#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{

public:

    Date(int month, int day, int year);

    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    std::string toString();

public:
    
    static std::string numericalMonthToStringMonth(int month);
    static int getDaysInMonth(int month);

private:
    int m_day, m_month, m_year;
};

#endif