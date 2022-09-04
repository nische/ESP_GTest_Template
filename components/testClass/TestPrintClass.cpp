#include "TestPrintClass.h"

TestPrintClass::TestPrintClass(std::shared_ptr<System::IChipInfo> chipInfo)
{
    info = chipInfo;
}

std::string TestPrintClass::GetTestString()
{
    int cores = info->GetNumberOfCores();
    return "Cores: " + cores;
}