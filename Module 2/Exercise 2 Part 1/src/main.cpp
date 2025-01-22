#include <iostream>

#include "Date.h"

using std::cout, std::cin;

bool showInteractiveMenu(Date &date)
{
    cout << date.toString() << '\n';
    cout << "1 - Set Day\n";
    cout << "2 - Set Month\n";
    cout << "3 - Set Year\n";
    cout << "4 - Exit\n";

    int choice;

    cout << ">> ";
    cin >> choice;

    switch (choice)
    {

    case 1:
    {
        int newDay;

        cout << "What day? ";
        cin >> newDay;

        try
        {
            date.setDay(newDay);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }

        break;
    }
    case 2:
    {
        int newMonth;

        cout << "What month? ";
        cin >> newMonth;

        try
        {
            date.setMonth(newMonth);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }

        break;
    }

    case 3:
    {
        int newYear;

        cout << "What year? ";
        cin >> newYear;

        try
        {
            date.setYear(newYear);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
        }

        break;
    }

    case 4:
        cout << "Goodbye!";
        return false;
    default:
        cout << "Invalid choice... try again.\n";
        break;
    }

    return true;
}

int main()
{
    int day, month, year;

    cout << "Enter a date (Ex. 9 28 2004): ";
    cin >> day >> month >> year;

    try
    {
        Date date(day, month, year);

        while (showInteractiveMenu(date)){}
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}