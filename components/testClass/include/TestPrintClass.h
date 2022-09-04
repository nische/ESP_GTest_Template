#pragma once
#include <string>
#include <memory>
#include "../../idf_cpp_wrapper/Interfaces/System/IChipInfo.h"

class TestPrintClass
{
public:
    TestPrintClass(std::shared_ptr<System::IChipInfo> chipInfo);
    ~TestPrintClass(){};
    std::string GetTestString();

private:
    std::shared_ptr<System::IChipInfo> info;
};
