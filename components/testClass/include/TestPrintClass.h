#pragma once
#include <string>
#include <memory>
#include "IChipInfo.h"

class TestPrintClass
{
public:
    TestPrintClass(std::shared_ptr<System::IChipInfo> chipInfo);
    ~TestPrintClass(){};
    std::string GetChipInfo();        //"This is %s chip with %d CPU core(s)"
    std::string GetWirelessInfo();    //"With WIFI/bt/ble"
    std::string GetMinHeapSizeInfo(); //"Minimum free heap size: %d bytes\n"
private:
    std::shared_ptr<System::IChipInfo> info;
};
