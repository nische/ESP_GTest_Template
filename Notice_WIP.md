# Setup 
1. Create unit_testfolder
2. add libs folder
3. add gtest as submodule in libs folder
4. add CmakeLists.txt in unit_test folder

# WSL Kernel Update
https://askubuntu.com/questions/1373910/ch340-serial-device-doesnt-appear-in-dev-wsl/

usbipd for windows:
https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/
https://github.com/dorssel/usbipd-win



# Cmake flags

option(RunTesting "RunTesting" OFF) -> CMakeLists.txt

-DRunTesting:BOOL=ON -> Commandline


