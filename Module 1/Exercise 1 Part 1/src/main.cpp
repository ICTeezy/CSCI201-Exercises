/*

    Author: Connor Taylor
    Date Written: 1/18/2025
    Assignment: Module 1 Exercise Part 1
    Description: The program allows the user to create a cube and update the different attributes of the cube.

*/

#include <iostream>

#include "Cube.h"

using std::cout, std::cin;

//Prompts user for a dimension, validates the input and returns a positive integer on success, -1 on fail.
int promptCubeDimension(std::string prompt, std::string failMessage)
{
    int dimension;

    cout << prompt;
    cin >> dimension;

    if (cin.fail()) //Checks for input other than integers
    {
        cout << failMessage << '\n';
        return -1;
    }

    if (dimension < 0) //We know dimension was an integer so we can bounds check it now
    {
        cout << failMessage << '\n';
        return -1;
    }

    return dimension;
}

int promptLength()
{
    return promptCubeDimension("Enter cube length: ", "Make sure the length is a whole integer > 0!");
}

int promptWidth()
{
    return promptCubeDimension("Enter cube width: ", "Make sure the width is a whole integer > 0!");
}

int promptHeight()
{
    return promptCubeDimension("Enter cube height: ", "Make sure the width is a whole integer > 0!");
}

bool displayMenu(Cube& cube)
{

    int choice; 

    cout 
    << "Cube (" << cube.getColor() << "): (" << cube.getLength() << "x" << cube.getWidth() << "x" << cube.getHeight() 
    << ") Volume: " << cube.calculateVolume() << "\n";
    cout << "Type a number to select and press ENTER: \n";
    cout << "1. Set Length\n";
    cout << "2. Set Width\n";
    cout << "3. Set Height\n";
    cout << "4. Set Color\n";
    cout << "5. Exit\n";
    cout << ">> ";

    cin >> choice; 

    switch(choice)
    {
        case 1:
        {
            int length = promptLength();

            if (length != -1) 
            {
                cube.setLength(length);
            }

            break;
        }
        case 2:
        {
            int width = promptWidth();

            if (width != -1) 
            {
                cube.setWidth(width);
            }

            break;
        }
        case 3:
        {
            int height = promptHeight();

            if (height != -1) 
            {
                cube.setHeight(height);
            }

            break;
        }
        case 4:
        {
            std::string color;

            cout << "Enter cube color: ";
            cin >> color;

            cube.setColor(color);
            break;
        }
        case 5:
            cout << "Bye!";
            return false;
            break;
        default:
            cout << "Unknown selection... try again.\n";
            break;
    }

    return true;
}

int main()
{

    //Grab inputs to create initial cube
    int length = promptLength();

    if (length == -1)
    {
        return -1;
    }

    int width = promptWidth();

    if (width == -1)
    {
        return -1;
    }

    int height = promptHeight();

    if (height == -1)
    {
        return -1;
    }

    std::string color;

    cout << "Enter cube color: ";
    cin >> color;

    Cube cube(length, width, height, color);

    //Display interactive menu until user quits
    while(displayMenu(cube)) {}
}