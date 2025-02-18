#include "Beverage.h"

Beverage::Beverage(std::string name, std::string description, int servingSize, int calories, double price)
    : m_name(name), m_description(description), m_servingSize(servingSize), m_calories(calories), m_price(price)
{
    
}

std::string Beverage::getName()
{
    return m_name;   
}

std::string Beverage::getDescription() 
{
    return m_description;   
}

int Beverage::getServingSize() 
{
    return m_servingSize;   
}

int Beverage::getCalories() 
{
    return m_calories;   
}

double Beverage::getPrice() 
{
    return m_price;   
}