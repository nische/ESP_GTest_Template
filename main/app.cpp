/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ChipInfo.h"
// #include "esp_system.h"
#include "esp_spi_flash.h"

extern "C" void app_main(void)
{
    printf("Hello world!\n");

    /* Print chip information */
    System::ChipInfo info;
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
           CONFIG_IDF_TARGET,
           info.GetNumberOfCores(),
           (info.GetFeatureBitMask() & CHIP_FEATURE_BT) ? "/BT" : "",
           (info.GetFeatureBitMask() & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", info.GetRevision());

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
           (info.GetFeatureBitMask() & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 10; i >= 0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
