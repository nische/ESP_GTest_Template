#include "gtest/gtest.h"

// int main(int argc, char **argv)
extern "C" void app_main(void)
{
    ::testing::InitGoogleTest();
    int ret = RUN_ALL_TESTS();
    // return ret;
}