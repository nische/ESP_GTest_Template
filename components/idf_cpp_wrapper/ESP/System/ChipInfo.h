#pragma once
#include "IChipInfo.h"

namespace System
{
    class ChipInfo : public IChipInfo
    {
    public:
        ChipInfo();
        // ~ChipInfo();
        esp_chip_model_t GetModel() override;
        uint32_t GetFeatureBitMask() override;
        uint8_t GetNumberOfCores() override;
        uint8_t GetRevision() override;

    private:
        esp_chip_info_t _info;
    };
} // namespace System
