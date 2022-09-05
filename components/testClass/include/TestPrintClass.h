#pragma once
#include <string>
#include <memory>
#include "IChipInfo.h"

class TestPrintClass
{
public:
    TestPrintClass(std::shared_ptr<System::IChipInfo> chipInfo);
    ~TestPrintClass(){};
    std::string GetTestString();

private:
    std::shared_ptr<System::IChipInfo> info;
};
