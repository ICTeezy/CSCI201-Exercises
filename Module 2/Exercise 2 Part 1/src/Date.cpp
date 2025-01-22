#include "Date.h"

#include <stdexcept>

void assertValidMonth(int month) 
{
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("Numeric month `" + std::to_string(month) + "` is invalid (1 >= month <= 12)");
    }
}

Date::Date(int month, int day, int year) 
{
    setMonth(month);
    setDay(day);
    setYear(year);
}

void Date::setMonth(int month) 
{
   assertValidMonth(month);

   m_month = month; 
}

void Date::setDay(int day) 
{
    int daysInMonth = getDaysInMonth(m_month);

    if (day < 1 || day > daysInMonth)
    {
        throw std::invalid_argument(
            "Numeric day `" + std::to_string(day) 
            + "` must be in range 1 >= day >= " + std::to_string(daysInMonth) 
            + " for the month of " + numericalMonthToStringMonth(m_month)
        );
    }

    m_day = day;
}

void Date::setYear(int year) 
{
    if (year < 1900 || year > 2020)
    {
        throw std::invalid_argument("Year must be in range 1900 >= year <= 2020");
    }

    m_year = year;
}

std::string Date::toString() 
{
    return numericalMonthToStringMonth(m_month) 
    + " " + std::to_string(m_day) 
    + ", " + std::to_string(m_year);
}

std::string Date::numericalMonthToStringMonth(int month) 
{
    assertValidMonth(month);

    switch (month)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}

int Date::getDaysInMonth(int month)
{
    assertValidMonth(month);

    switch (month)
    {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}