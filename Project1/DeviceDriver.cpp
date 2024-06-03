#include "DeviceDriver.h"
#include "windows.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class ReadFailException : public exception {

};

class WriteFailException : public exception {

};

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
            throw ReadFailException();
    }
    return nReturn;
}

void DeviceDriver::write(long address, int data)
{
    if (read(address) != 0xFF)
        throw WriteFailException();
    m_hardware->write(address, (unsigned char)data);
}
