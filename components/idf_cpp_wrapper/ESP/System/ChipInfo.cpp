#include "ChipInfo.h"

namespace System
{
    ChipInfo::ChipInfo()
    {
        esp_chip_info(&_info);
    }

    esp_chip_model_t ChipInfo::GetModel()
    {
        return _info.model;
    }
    uint32_t ChipInfo::GetFeatureBitMask()
    {
        return _info.features;
    }
    uint8_t ChipInfo::GetNumberOfCores()
    {
        return _info.cores;
    }
    uint8_t ChipInfo::GetRevision()
    {
        return _info.revision;
    }

} // namespace system
