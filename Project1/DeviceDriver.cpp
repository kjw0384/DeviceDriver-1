#include "DeviceDriver.h"
#include "windows.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int nReturn = 0;
    int nReadValue = 0;
    
    nReturn = (int)(m_hardware->read(address));
    for (int i = 0; i < 4; i++)
    {
        Sleep(200);
        nReadValue = (int)(m_hardware->read(address));

        if (nReturn != nReadValue)
            return -1;
    }
    return nReturn;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}
