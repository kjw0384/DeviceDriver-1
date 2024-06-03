#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    int nReturn = 0;
    int nReadValue = 0;
    for (int i = 0; i < 5; i++)
    {
        nReadValue = (int)(m_hardware->read(address));
        if (i == 0)
            nReturn = nReadValue;
        else if (nReturn != nReadValue)
            return -1;
    }
    return nReturn;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}
