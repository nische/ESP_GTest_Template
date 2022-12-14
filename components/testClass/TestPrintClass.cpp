#include "TestPrintClass.h"

TestPrintClass::TestPrintClass(std::shared_ptr<System::IChipInfo> chipInfo)
{
    info = chipInfo;
}

std::string TestPrintClass::GetChipInfo()
{
    int cores = info->GetNumberOfCores();
    return "Cores: " + std::to_string(cores);
}