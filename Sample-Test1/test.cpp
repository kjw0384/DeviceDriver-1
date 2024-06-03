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

class DeviceDriverFixture : public testing::Test {
public:
	MockFlashMemoryDevice mDevice;
	DeviceDriver driver{ &mDevice };
};

TEST_F(DeviceDriverFixture, Read5Test) {
	EXPECT_CALL(mDevice, read(0))
		.Times(5);

	driver.read(0);
}

TEST_F(DeviceDriverFixture, ReadFail) {
	EXPECT_CALL(mDevice, read(0))
		.WillOnce(Return(0))
		.WillOnce(Return(0))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	EXPECT_THROW(driver.read(0), ReadFailException);
}

TEST_F(DeviceDriverFixture, WriteCheckCurrentWritten) {
	EXPECT_CALL(mDevice, read(0))
		.WillRepeatedly(Return(0));

	EXPECT_THROW(driver.write(0, 'A'), WriteFailException);
}

TEST_F(DeviceDriverFixture, WriteNormal) {
	EXPECT_CALL(mDevice, read(0))
		.WillRepeatedly(Return(0xFF));
	EXPECT_CALL(mDevice, write)
		.Times(1);

	driver.write(0, 'A');
}
