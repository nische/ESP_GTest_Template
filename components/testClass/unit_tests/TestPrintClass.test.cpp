#include <gtest/gtest.h>
#include "../include/TestPrintClass.h"
#include "../../idf_cpp_wrapper/Mocks/System/ChipInfoMock.h"

using namespace testing;

class TestPrintClassFixture : public testing::Test
{
public:
    std::shared_ptr<NiceMock<System::ChipInfoMock>> chipInfoMock;
    std::shared_ptr<TestPrintClass> sut;

    TestPrintClassFixture()
    {
        chipInfoMock = std::make_shared<NiceMock<System::ChipInfoMock>>();
        sut = std::make_shared<TestPrintClass>(chipInfoMock);
    }
    ~TestPrintClassFixture() {}
};

TEST_F(TestPrintClassFixture, GetTestString_TestToFail_ReturnNotSameAsExpected)
{
    EXPECT_CALL(*chipInfoMock, GetNumberOfCores()).Times(1).WillOnce(Return((uint8_t)(2)));
    EXPECT_EQ("Cores: 24", sut->GetTestString());
}

TEST_F(TestPrintClassFixture, GetTestString_TestToWin_ReturnSameAsExpected)
{
    EXPECT_CALL(*chipInfoMock, GetNumberOfCores()).Times(1).WillOnce(Return((uint8_t)(24)));
    EXPECT_EQ("Cores: 24", sut->GetTestString());
}