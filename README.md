# Micro Arena: Example Bot C++
This servers as an example C++ bot for the [micro arena ladder](https://ai-arena.net/).

# Developer Install / Compile Instructions
## Requirements
* [CMake](https://cmake.org/download/)
* Starcraft 2 ([Windows](https://starcraft2.com/en-us/)) ([Linux](https://github.com/Blizzard/s2client-proto#linux-packages))

## Windows

* Download and install [Visual Studio 2017](https://www.visualstudio.com/downloads/) if you need it.

```bat
:: Clone the project
$ git clone --recursive https://github.com/lladdy/MicroArenaExampleBotCpp.git
$ cd MicroArenaExampleBotCpp

:: Create build directory.
$ mkdir build
$ cd build

:: Generate VS solution.
$ cmake ../ -G "Visual Studio 15 2017 Win64"

:: Build the project using Visual Studio.
$ start MicroArenaExampleBotCpp.sln
```

 ### Linux and OS X
 
 ```bash
 # Clone the project.
 $ git clone --recursive https://github.com/lladdy/MicroArenaExampleBotCpp.git
 $ cd MicroArenaExampleBotCpp
 
 # Create build directory.
 $ mkdir build
 $ cd build
 
 # Generate a Makefile.
 $ cmake ../
 
 # Build.
 $ make
 ```

### Submodules
If you don't initially do a `--recursive` clone (in which case, s2client-api submodule folder will be left empty), you can initialize the submodule later like so:
```
git submodule update --init --recursive
```

