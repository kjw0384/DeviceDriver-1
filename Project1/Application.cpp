#include "DeviceDriver.h"

class App {
public:
	const int ADDR_WRITE_START = 0x00;
	const int ADDR_WRITE_END = 0x04;

	App(DeviceDriver* input_driver) : driver(input_driver) {}
	void ReadAndPrint(int startAddr, int endAddr) {
		for (int iAddr = startAddr; iAddr <= endAddr; iAddr++)
		{
			driver->read(iAddr);
		}
	}

	void WriteAll(int value) {
		for (int iAddr = ADDR_WRITE_START; iAddr <= ADDR_WRITE_END; iAddr++)
			driver->write(iAddr, value);
	}
private:
	DeviceDriver* driver;
};
