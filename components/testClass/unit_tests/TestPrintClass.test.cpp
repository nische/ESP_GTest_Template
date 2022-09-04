#include "gtest/gtest.h"
#include "../include/TestPrintClass.h"
#include "../../idf_cpp_wrapper/Mocks/System/ChipInfoMock.h"

using namespace testing;

class TestPrintClassFixture : public testing::Test
{
public:
    std::shared_ptr<NiceMock<System::IChipInfo>> chipInfoMock;
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
    EXPECT_CALL(*chipInfoMock, GetNumberOfCores()).Times(1); //.WillOnce(Return((uint8_t)(2)));
    EXPECT_EQ("Cores: 2", sut->GetTestString());
}
