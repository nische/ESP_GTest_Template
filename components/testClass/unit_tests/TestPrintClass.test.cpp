#include "gtest/gtest.h"
#include "../include/TestPrintClass.h"

class TestPrintClassFixture : public testing::Test
{
public:
    TestPrintClassFixture() {}
    ~TestPrintClassFixture() {}

    TestPrintClass sut;
};

TEST_F(TestPrintClassFixture, GetTestString_TestToFail_ReturnNotSameAsExpected)
{
    EXPECT_EQ("Wrong", sut.GetTestString());
}
