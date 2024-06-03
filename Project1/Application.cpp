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

private:
	DeviceDriver* driver;
};
