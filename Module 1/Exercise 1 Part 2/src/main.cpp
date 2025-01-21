/*

    Author: Connor Taylor
    Date Written: 1/19/2025
    Assignment: Module 1 Exercise Part 2
    Description: The program allows the user to create a stereo and update the different attributes of it.

*/

#include <iostream>
#include <string>

#include "StereoReceiver.h"

using std::cout, std::cin;

int readPositiveInteger(std::string failMessage)
{
    int integer;
    cin >> integer;

    if (cin.fail())
    {
        cout << failMessage << '\n';
        return -1;
    }

    if (integer < 0)
    {
        cout << failMessage << '\n';
        return -1;
    }

    return integer;
}

bool displayMenu(StereoReceiver& receiver)
{

    if (!receiver.isPowered())
    {
        cout << "--- OFF ---\n";
        cout << "1. Details\n";
        cout << "2. Power On\n";

        int choice = readPositiveInteger("Selection should be an integer >= 0!");

        if (choice == -1)
        {
            return true;
        }

        if (choice == 1)
        {
            receiver.printDetails();
        }
        else if (choice == 2)
        {
            receiver.powerOn();
        }
        else
        {
            cout << "Unknown selection... try again.\n";
        }

        return true;
    }

    std::string bandString = receiver.getBand() == Band::AM ? "AM" : "FM";

    cout << receiver.getFrequency() << "Hz";
    cout << " - " << bandString << " | ";
    cout << "Volume [" << receiver.getVolume() << "/" << VOLUME_MAX << "] | ";

    if (receiver.isBluetoothEnabled())
    {
        cout << "Bluetooth: ON | ";
    }
    else
    {
        cout << "Bluetooth: OFF | ";
    }

    cout << "Bass Boost [" << receiver.getBassBoost() << "/" << BASS_MAX << "]\n";
    
    cout << "1. Details\n";
    cout << "2. Toggle Band\n";
    cout << "3. Increase Volume\n";
    cout << "4. Decrease Volume\n";
    cout << "5. Increase Bass\n";
    cout << "6. Decrease Bass\n";
    cout << "7. Set Frequency\n";
    cout << "8. Toggle Bluetooth\n";
    cout << "9. Power Off\n";
    cout << "10. Exit\n";

    cout << ">> ";
    int choice = readPositiveInteger("Selection should be an integer >= 0!");

    switch (choice)
    {
        case 1:
            receiver.printDetails();
            break;
        case 2:
            receiver.setBand(receiver.getBand() == Band::AM ? Band::FM : Band::AM);
            break;
        case 3:
        {
            cout << "Increase by how much? ";
            int increaseAmount = readPositiveInteger("Volume increase must be a positive integer!");

            if (increaseAmount == -1)
            {
                break;
            }

            receiver.increaseVolume(increaseAmount);
            break;
        }
        case 4:
        {
            cout << "Decrease by how much? ";
            int decreaseAmount = readPositiveInteger("Volume decrease must be a positive integer!");

            if (decreaseAmount == -1)
            {
                break;
            }

            receiver.decreaseVolume(decreaseAmount);
            break;
        }
        case 5:
        {
            cout << "Increase by how much? ";
            int increaseAmount = readPositiveInteger("Bass increase must be a positive integer!");

            if (increaseAmount == -1)
            {
                break;
            }

            receiver.increaseBass(increaseAmount);
            break;
        }
        case 6:
        {
            cout << "Decrease by how much? ";
            int decreaseAmount = readPositiveInteger("Bass decrease must be a positive integer!");

            if (decreaseAmount == -1)
            {
                break;
            }

            receiver.decreaseBass(decreaseAmount);
            break;
        }
        case 7:
        {
            cout << "Frequency: ";
            int frequency = readPositiveInteger("Frequency must be a positive integer!");

            if (frequency == -1)
            {
                break;
            }

            receiver.setFrequency(frequency);
            break;
        }
        case 8:
        {
            receiver.toggleBluetooth();
            break;
        }
        case 9:
        {
            cout << "Powering off...\n";
            receiver.powerOff();
            break;
        }
        case 10:
        {
            cout << "Bye!";
            return false;
        }
        default:
            cout << "Unknown selection... try again.\n";
            break;
    }

    return true;
}

int main()
{

    std::string manufacturer, model, serialNumber;

    cout << "Please provide the details of your stereo!\n";

    cout << "Manufacturer: ";
    cin >> manufacturer;

    cout << "Model: ";
    cin >> model;

    cout << "Serial Number: ";
    cin >> serialNumber;

    cout << "Wattage: ";
    int wattage = readPositiveInteger("Wattage should be an integer > 0!");
    if (wattage == -1)
    {
        return -1;
    }

    cout << "Number of Channels: ";
    int numberOfChannels = readPositiveInteger("The number of channels should be an integer > 0!");
    if (numberOfChannels == -1)
    {
        return -1;
    }

    StereoReceiver receiver(manufacturer, model, serialNumber, wattage, numberOfChannels);

    while (displayMenu(receiver)) {}
}