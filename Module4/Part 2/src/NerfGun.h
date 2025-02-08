#ifndef NERFGUN_H
#define NERFGUN_H

#include <iostream>
#include <string>

class NerfGun
{

    public:

    NerfGun(std::string model, int range, int capacity);

    std::string getModel();
    int getCapacity();
    int getDartCount() const;
    void fire();
    void reload(int quantity);

    bool operator==(const NerfGun& other);
    bool operator<(const NerfGun& other);
    void operator--();
    void operator--(int);
    void operator+=(int quantity);
    friend std::ostream& operator<<(std::ostream& out, const NerfGun& gun);


    private:

    std::string m_model;
    int         m_range;
    int         m_capacity;
    int         m_numberOfDarts;

};

#endif