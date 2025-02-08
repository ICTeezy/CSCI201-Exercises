#include "NerfGun.h"

#include <stdexcept>

NerfGun::NerfGun(std::string model, int range, int capacity)
    :m_model(model), m_range(range), m_capacity(capacity)
{
    
}

std::string NerfGun::getModel()
{
    return m_model;   
}

int NerfGun::getCapacity() 
{
    return m_capacity;   
}

int NerfGun::getDartCount() const
{
    return m_numberOfDarts;   
}

void NerfGun::fire() 
{
    if (m_numberOfDarts == 0)      
    {
        throw std::underflow_error("Attempted to fire gun with no ammo!");
    }

    m_numberOfDarts--;
}

void NerfGun::reload(int quantity) 
{
    if (quantity + m_numberOfDarts > m_capacity)
    {
        throw std::overflow_error("Attempted to reload and exceeded gun capacity!");
    }

    m_numberOfDarts += quantity;
}

bool NerfGun::operator==(const NerfGun& other) 
{
    return m_numberOfDarts == other.m_numberOfDarts;   
}

bool NerfGun::operator<(const NerfGun &other)
{
    return m_numberOfDarts < other.m_numberOfDarts;
}

void NerfGun::operator--()
{
    fire();
}

void NerfGun::operator--(int) 
{
    fire();   
}

void NerfGun::operator+=(int quantity) 
{
    reload(quantity);
}

std::ostream& operator<<(std::ostream& out, const NerfGun& gun) {
    out << "Model: " << gun.m_model 
        << " Range: " << gun.m_range 
        << " Capacity: " << gun.m_capacity 
        << " Darts: " << gun.getDartCount();
    return out;
}
