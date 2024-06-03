#include "DeviceDriver.h"

class App {
public:
	App(DeviceDriver* input_driver) : driver(input_driver) {}
	void ReadAndPrint(int startAddr, int endAddr) {
		for (int i = startAddr; i <= endAddr; i++)
		{
			driver->read(i);
		}
	}

	void WriteAll(int value) {
		for (int i = 0; i <= 4; i++)
			driver->write(i, value);
	}
private:
	DeviceDriver* driver;
};
