#include "StereoReceiver.h"

#include <iostream>


StereoReceiver::StereoReceiver(

    std::string manufacturer, 
    std::string model, 
    std::string serialNumber, 
    int wattage, int numberOfChannels

)
:   m_manufacturer(manufacturer), 
    m_model(model), 
    m_serialNumber(serialNumber),
    m_wattage(wattage), 
    m_numberOfChannels(numberOfChannels),
    m_band(Band::AM),
    m_volume(3),
    m_frequency(100),
    m_powered(false),
    m_bassBoost(0),
    m_bluetoothEnabled(false)
{
}

std::string StereoReceiver::getManufacturer()
{
   return m_manufacturer;
}

std::string StereoReceiver::getModel()
{
    return m_model;
}

std::string StereoReceiver::getSerialNumber() 
{
    return m_serialNumber;
}

int StereoReceiver::getWattage()
{
    return m_wattage;   
}

int StereoReceiver::getNumberOfChannels() 
{
    return m_numberOfChannels;   
}

Band StereoReceiver::getBand() 
{
    return m_band;   
}

int StereoReceiver::getFrequency()
{
    return m_frequency;   
}

int StereoReceiver::getVolume() 
{
    return m_volume;   
}

int StereoReceiver::getBassBoost()
{
    return m_bassBoost;
}

bool StereoReceiver::isPowered() 
{
    return m_powered;   
}

bool StereoReceiver::isBluetoothEnabled()
{
    return m_bluetoothEnabled;
}

void StereoReceiver::powerOff() 
{
    m_band = Band::AM;
    m_volume = 3;
    m_frequency = 100;
    m_bassBoost = 0;
    m_bluetoothEnabled = false;
    m_powered = false;   
}

void StereoReceiver::powerOn() 
{
    m_powered = true;   
}

void StereoReceiver::increaseVolume(int increase) 
{
   if (m_volume + increase > VOLUME_MAX)    
   {
        m_volume = VOLUME_MAX;
   }
   else
   {
        m_volume += increase;
   }
}

void StereoReceiver::decreaseVolume(int decrease) 
{
    if (m_volume - decrease < VOLUME_MIN)   
    {
        m_volume = VOLUME_MIN;
    }
    else
    {
        m_volume -= decrease;
    }
}

void StereoReceiver::setBand(Band band) 
{
    m_band = band;   
}

void StereoReceiver::setFrequency(int frequency) 
{
    m_frequency = frequency;   
}

void StereoReceiver::toggleBluetooth()
{
    m_bluetoothEnabled = !m_bluetoothEnabled;
}

void StereoReceiver::increaseBass(int increase)
{

    if (m_bassBoost + increase > BASS_MAX)
    {
        m_bassBoost = BASS_MAX;
    }
    else
    {
        m_bassBoost += increase;
    }

}

void StereoReceiver::decreaseBass(int decrease)
{
    if (m_bassBoost - decrease < BASS_MIN)
    {
        m_bassBoost = BASS_MIN;
    }
    else
    {
        m_bassBoost -= decrease;
    }
}

void StereoReceiver::printDetails()
{
    std::cout << "Manufacturer - " << m_manufacturer << '\n';
    std::cout << "Model - " << m_model << '\n';
    std::cout << "Serial Number - " << m_serialNumber << '\n';
    std::cout << "Wattage - " << m_wattage << '\n';
}
