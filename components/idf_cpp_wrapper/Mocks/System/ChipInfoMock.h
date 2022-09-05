#pragma once
#include <gmock/gmock.h>

#include "../../Interfaces/System/IChipInfo.h"

namespace System
{
    class ChipInfoMock : public IChipInfo
    {
    public:
        // virtual esp_chip_model_t GetModel() = 0;
        MOCK_METHOD(esp_chip_model_t, GetModel, (), (override));
        // virtual uint32_t GetFeatureBitMask() = 0;
        MOCK_METHOD(uint32_t, GetFeatureBitMask, (), (override));
        // virtual uint8_t GetNumberOfCores() = 0;
        MOCK_METHOD(uint8_t, GetNumberOfCores, (), (override));
        // virtual uint8_t GetRevision() = 0;
        MOCK_METHOD(uint8_t, GetRevision, (), (override));
    };
}
