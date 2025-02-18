#include <iostream>

#include "Beverage.h"

class Soda : public Beverage
{

    public:

    Soda(std::string brand, std::string type, bool diet)
        : Beverage(
            "Soda",
            "A sugary syrupy stomach eating drink!",
            1,
            50,
            2.00
        ), m_brand(brand), m_type(type), m_diet(diet)
    {

    }

    std::string toString()
    {
        return "Brand: " + m_brand + " Type: " + m_type + " Diet: " + (m_diet ? "Yes" : "No");
    }

    private:

    std::string m_brand;
    std::string m_type;
    bool m_diet;

};

class EnergyDrink : public Beverage
{

    public:

    EnergyDrink(std::string brand, std::string stimulant, bool sweetener)
        : Beverage(
            "Energy Drink",
            "A drink to boost your day!",
            1,
            100,
            5.00
        ), m_brand(brand), m_stimulant(stimulant), m_sweetener(sweetener)
    {
        
    }

    std::string toString()
    {
        return "Brand: " + m_brand + " Stimulant: " + m_stimulant + " Sweetener: " + (m_sweetener ? "Yes" : "No");
    }

    private:

    std::string m_brand;
    std::string m_stimulant;
    bool m_sweetener;

};

class Tea : public Beverage
{

    public:

    Tea(std::string type, bool hot, bool creamer, bool sweetener, bool lemon)
        : Beverage(
            "Tea",
            "A nice and drink for when you're sick.",
            1,
            25,
            2.50
        ), m_type(type), m_hot(hot), m_creamer(creamer), m_sweetener(sweetener), m_lemon(lemon)
    {

    }

    std::string toString()
    {
        return "Type: " + m_type + 
        " Hot: " + (m_hot ? "Yes" : "No") + 
        " Creamer: " + (m_creamer ? "Yes" : "No") + 
        " Sweetener: " + (m_sweetener ? "Yes" : "No") + 
        " Lemon: " + (m_lemon ? "Yes" : "No");
    }

    private:

    std::string m_type;
    bool m_hot;
    bool m_creamer;
    bool m_sweetener;
    bool m_lemon;

};

class Coffee : public Beverage
{

    public:

    Coffee(bool hot, bool caffeinated, std::string roastType, int strength, bool creamer, bool sweetener)
        : Beverage(
            "Coffee",
            "The drink that's running the world!",
            1,
            400,
            7.50
        ), m_hot(hot), m_caffeinated(caffeinated), m_roastType(roastType), m_strength(strength), m_creamer(creamer), m_sweetener(sweetener)
    {

    }

    std::string toString()
    {
        return "Roast Type: " + m_roastType +
        " Hot: " + (m_hot ? "Yes" : "No") +
        " Caffeinated: " + (m_caffeinated ? "Yes" : "No") +
        " Strength: " + std::to_string(m_strength) +
        " Creamer: " + (m_creamer ? "Yes" : "No") + 
        " Sweetener: " + (m_sweetener ? "Yes" : "No");
    }

    private:

    bool m_hot;
    bool m_caffeinated;
    std::string m_roastType;
    int m_strength;
    bool m_creamer;
    bool m_sweetener;

};


int main()
{
    Soda soda("Sprite", "Lemon-Lime", false);
    Tea tea("Iced Gingerbread Oatmilk Chai", false, true, true, false);
    EnergyDrink energyDrink("Redbull", "caffeine", true);
    Coffee coffee(false, true, "Light", 4, true, true);

    std::cout << soda.toString() << '\n';
    std::cout << tea.toString() << '\n';
    std::cout << energyDrink.toString() << '\n';
    std::cout << coffee.toString() << '\n';
}