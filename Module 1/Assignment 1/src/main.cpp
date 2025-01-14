#include <iostream>
#include <cstring>

#include "Cube.h"

using std::cout, std::cin;

bool validateCubeDimension(int dimension, char *message)
{
    if (cin.fail())
    {
        std::cout << message;
        return -false;
    }

    return dimension > 0;
}

int main()
{

    int length, width, height;

    cout << "Enter cube length: ";
    cin >> length;

    if (!validateCubeDimension(length, "Make sure the length is a whole integer > 0!"))
    {
        return -1;
    }

    cout << "Enter cube width: ";
    cin >> width;

    if (!validateCubeDimension(width, "Make sure the width is a whole integer > 0!"))
    {
        return -1;
    }

    cout << "Enter cube height: ";
    cin >> height;

    if (!validateCubeDimension(height, "Make sure the height is a whole integer > 0!"))
    {
        return -1;
    }

    char colorBuffer[1024];

    cout << "Enter cube color: ";
    cin >> colorBuffer;

    Cube cube(length, width, height, colorBuffer);

}