#include <iostream>

#include "PersonalComputer.h"

int main()
{
    PersonalComputer computer("", FormFactor::DESKTOP, "", "", 1, StorageType::SDD, 1);
    std::cout << computer.getSerialNumber() << '\n';
}