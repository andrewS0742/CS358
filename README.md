# Ranked Ballot Counter

A program to read ranked ballot files and determine a winner.

## Getting Started

### Dependencies

* RapidCSV (https://github.com/d99kris/rapidcsv) (required header is already included in src)
* Nanogui (https://github.com/wjakob/nanogui)
* CMake (to generate nanogui VS project) (https://cmake.org/download/)

### Installing

* Install CMake
* Clone Nanogui
* Clone this repo

* Follow the compilation instructions in the Nanogui README
* Compile nanogui lib and dll files (build nanogui project in Visual Studio)

#### Updating VS Project
* Under Ranked Ballot Counter Project > Properties > C++ > General > Additional Include Directories, add your nanogui/include folder
* Under Linker > General > Additional Library Directories, add the folder containing your nanogui.dll/lib file (likely in nanogui/build if created)
* Under Linker > Input > Additional Dependencies add 'nanogui.lib'

### Executing program

* Compile and run Ranked Ballot Counter through VS
* Copy nanogui.dll into CS358/x64/(Debug or Release)/ if needed
