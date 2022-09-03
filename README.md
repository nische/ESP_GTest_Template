# Template for GoogleTest/Mock with ESP-IDF
Started Project to work with Google Test, ESP-IDF and nativ in a devcontainer.

I still work on this but only at late nigth. 

[ ] Start wrapping some usefull Components
[ ] Fix Documentation
[ ] Add ExampleTest with Mock Calls


# Gettin Started
If needed -> Issue 

## Use Nativ
To Build the Tests on Linux there are a few Tasks:
- Setup Tests (nativ)
- Build Tests (nativ)
- Run Tests (nativ)
- Clean Tests (nativ)

To use the Mocks from "idf_cpp_wrapper" there will be set the Variable "RuntTests" in CMakeLists.txt.

## Use ESP
ESP dont find test if i tryed. -> maybe in the future. 
i oldered a lot if i tryed to run the tests on the ESP

## Example folder contents
The Project looks like a normal ESP Hello World but there is the a additional "unit_tests"-Folder.
Also in the componets folder "googletest" and idf_cpp_wrapper" is needed.
### Main Folder
```
├── CMakeLists.txt              ESP-IDF Project File
├── main
│   ├── CMakeLists.txt
│   ├── component.mk            Component make file
│   └── app.cpp
├── Makefile                    Makefile used by legacy GNU Make 
├── README.md                   This is the file you are currently reading
├── unit_tests                  Folder with magic nativ unittest
│   ├── CMakeLists.txt          Main CMake File for nativ Tests (incl. esp-idf function overload and Cmake magic)
│   └── testrunner.cpp          Source file for GTest
└── components                  ESP-IDF Components Folder
```
### Componentsfolder
To add test to a Componet just add a filder named "unit_tests" in root.
The Test files need to name like "blabla.test.cpp" (the ending *.test.cpp will bee autodetected)
```
├── components                      Folder with magic nativ unittest
│   ├── testClass          
│   │   ├── include          
│   │   |   ├── TestPrintClass.h    Tested Class Header         
│   │   |   └── ITestPrinteres.h    Interace for Tested Class         
│   │   ├── unit_tests          
│   │   |   └── TestPrinterClass.test.cpp    Tests for TestPrintClass        
│   ├── CMakeLists.txt              IDF like file (without tests in sourcelist/ use "RunTests" to define Mocks)
│   └── TestPrintClass.cpp          Tested Class Sourcefile
```

## IDF Wrapper
i start to build a ESP-IDF C++ Wrapper with Interfaces.
The Component is split in three Parts:
1. Interaces
2. ESP Target Code
3. Mocks

The CMakeLists files build Mocks or target code by the "RunTests"-Flag. 

For more info take a look in the "idf_cpp_wrapper"-Folder/CMakeLists.txt or ask me in an Issue.

## Troubleshooting
### ESP not found in Devcontainer (Windows)
__WIP If needed faster -> Issue__
usbipd for windows:
https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/
https://github.com/dorssel/usbipd-win
### USB<-> Serial Chip not deteced as tty in Devcontainer
__WIP If needed faster -> Issue__
WSL Kernel Update needed
https://askubuntu.com/questions/1373910/ch340-serial-device-doesnt-appear-in-dev-wsl/

## Technical support and feedback
I will add wrapped IDF Componentes if i need them. 
In the futur i want to use the KConfig Flags from "idf.py menuconfig" to build wrapper too. 

Feel free to add an Issue for needed Componet and/or implement them.
