#include "PersonalComputer.h"

void assertRamSize(int ramSizeGigabytes)
{

}

void assertStorageSize(int storageSizeGigabytes)
{

}

PersonalComputer::PersonalComputer(

    std::string manufacturer, 
    FormFactor formFactor, 
    std::string serialNumber, 
    std::string processor, 
    int ramSizeGigabytes, 
    StorageType storageType, 
    int storageSizeGigabytes

) : m_manufacturer(manufacturer),
    m_formFactor(formFactor),
    m_serialNumber(serialNumber),
    m_processor(processor),
    m_storageType(storageType)
{
    setRAMSize(ramSizeGigabytes);
    setStorageSize(storageSizeGigabytes);
}