#pragma once
#include <esp_system.h>

namespace System
{
    class IChipInfo
    {
    public:
        virtual esp_chip_model_t GetModel() = 0;
        virtual uint8_t GetNumberOfCores() = 0;
        virtual uint8_t GetRevision() = 0;

        virtual uint32_t GetFeatureBitMask() = 0;
        virtual bool HasEmbeddedFlash() = 0;
        virtual bool HasWifi2_4() = 0;
        virtual bool HasBLE() = 0;
        virtual bool HasBluetoth() = 0;
    };
}
