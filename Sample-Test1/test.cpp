#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DeviceDriver.cpp"
#include "../Project1/FlashMemoryDevice.h"


class MockFlashMemoryDevice : public FlashMemoryDevice {
public:
	// FlashMemoryDevice을(를) 통해 상속됨
	//unsigned char read(long address) override
	//{
	//	return 0;
	//}
	void write(long address, unsigned char data) override
	{
	}

	MOCK_METHOD(unsigned char, read, (long address), (override));
};

TEST(FlashMemoryTest, ReadTest) {
	MockFlashMemoryDevice mDevice;

	EXPECT_CALL(mDevice, read(0))
		.Times(5);

	DeviceDriver d(&mDevice);
	d.read(0);
}
