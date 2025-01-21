#include <string>

enum Band
{
    AM, FM
};

const int VOLUME_MAX = 10;
const int VOLUME_MIN = 0;

const int BASS_MAX = 5;
const int BASS_MIN = 0;

class StereoReceiver
{

private:
    std::string m_manufacturer;
    std::string m_model;
    std::string m_serialNumber;
    int         m_wattage;
    int         m_numberOfChannels;
    Band        m_band;
    int         m_frequency;
    int         m_volume;
    int         m_bassBoost;
    bool        m_bluetoothEnabled;
    bool        m_powered;

public:

    StereoReceiver(
        std::string manufacturer, 
        std::string model, 
        std::string serialNumber, 
        int wattage, int numberOfChannels
    );

    std::string getManufacturer();
    std::string getModel();
    std::string getSerialNumber();
    int         getWattage();
    int         getNumberOfChannels();
    Band        getBand();
    int         getFrequency();
    int         getVolume();
    int         getBassBoost();
    bool        isPowered();
    bool        isBluetoothEnabled();

    void powerOff();
    void powerOn();
    void increaseVolume(int increase);
    void decreaseVolume(int decrease);
    void setBand(Band band);
    void setFrequency(int frequency);
    void toggleBluetooth();
    void increaseBass(int increase);
    void decreaseBass(int decrease);

    void printDetails();

};