#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage
{

    public:

    Beverage(
        std::string name,
        std::string description,
        int servingSize,
        int calories,
        double price
    );

    std::string getName();
    std::string getDescription();
    int         getServingSize();
    int         getCalories();
    double      getPrice();

    private:

    std::string m_name;
    std::string m_description;
    int         m_servingSize;
    int         m_calories;
    double      m_price;

};

#endif