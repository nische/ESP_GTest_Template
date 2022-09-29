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

TEST_F(TestPrintClassFixture, GetChipInfo_TryGetModel_CallGetModelFromMock)
{
    EXPECT_CALL(*chipInfoMock, GetNumberOfCores()).Times(1).WillOnce(Return((uint8_t)(2)));
    EXPECT_EQ("Cores: 24", sut->GetChipInfo());
}
TEST_F(TestPrintClassFixture, GetChipInfo_Mockreturnesp32_ReturnStringWithESP32AsChip)
{
    EXPECT_CALL(*chipInfoMock, GetNumberOfCores()).Times(1).WillOnce(Return((uint8_t)(2)));
    EXPECT_EQ("Cores: 24", sut->GetChipInfo());
}
TEST_F(TestPrintClassFixture, GetChipInfo_MockReturnEsp32S2_ReturnStringWithESP32S2AsChip)
{
    EXPECT_TRUE(false);
}

TEST_F(TestPrintClassFixture, GetChipInfo_TryGetCoreNiuumbers_CallGetCoreNumbersFromMock)
{
    EXPECT_TRUE(false);
}

TEST_F(TestPrintClassFixture, GetChipInfo_Mockreturn2_ReturnStringWith2Cores)
{
    EXPECT_TRUE(false);
}
TEST_F(TestPrintClassFixture, GetChipInfo_MockReturn24_ReturnStringWith24Cores)
{
    EXPECT_TRUE(false);
}