#ifndef PERSONAL_COMPUTER_HEAD
#define PERSONAL_COMPUTER_HEAD

#include <string>

enum FormFactor
{
    LAPTOP,
    DESKTOP
};

enum StorageType
{
    UFS,
    SDD,
    HDD
};

class PersonalComputer
{

public:

    PersonalComputer(
        std::string manufacturer,
        FormFactor formFactor,
        std::string serialNumber,
        std::string processor,
        int ramSizeGigabytes,
        StorageType storageType,
        int storageSizeGigabytes
    );

    std::string getManufacturer();
    FormFactor  getFormFactor();
    std::string getSerialNumber();
    std::string getProcessor();
    int         getRAMSizeGigabytes();
    StorageType getStorageType();
    int         getStorageSizeGigabytes();

    void        setRAMSize(int ramSizeGigabytes);
    void        setStorageSize(int storageSizeGigabytes);
    void        setStorageType(StorageType type);

private:

    std::string m_manufacturer;
    FormFactor  m_formFactor;
    std::string m_serialNumber;
    std::string m_processor;
    int         m_ramGigabytes;
    StorageType m_storageType;
    int         m_storageSizeGigabytes;

};

#endif