#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DeviceDriver.cpp"
#include "../Project1/FlashMemoryDevice.h"

using namespace testing;

class MockFlashMemoryDevice : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long, unsigned char), (override));
};

TEST(DeviceDriverTest, Read5Test) {
	MockFlashMemoryDevice mDevice;

	EXPECT_CALL(mDevice, read(0))
		.Times(5);

	DeviceDriver driver(&mDevice);
	driver.read(0);
}

TEST(DeviceDriverTest, ReadFail) {
	MockFlashMemoryDevice mDevice;

	EXPECT_CALL(mDevice, read(0))
		.WillOnce(Return(0))
		.WillOnce(Return(0))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	DeviceDriver driver(&mDevice);
	EXPECT_THROW(driver.read(0), ReadFailException);
}

TEST(DeviceDriverTest, WriteCheckCurrentWritten) {
	MockFlashMemoryDevice mDevice;

	EXPECT_CALL(mDevice, read(0))
		.WillRepeatedly(Return(0));

	DeviceDriver driver(&mDevice);
	EXPECT_THROW(driver.write(0, 'A'), WriteFailException);
}

TEST(DeviceDriverTest, WriteNormal) {
	MockFlashMemoryDevice mDevice;

	EXPECT_CALL(mDevice, read(0))
		.WillRepeatedly(Return(0xFF));
	EXPECT_CALL(mDevice, write)
		.Times(1);

	DeviceDriver driver(&mDevice);
	driver.write(0, 'A');
}
