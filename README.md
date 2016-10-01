# Matlab-from-cpp

This repository is a very simple template of CPP (possibly C with minor modifications) code calling a Matlab function.

The only requirement is a (valid) installation of Matlab and a recent version of CMake. See section Installation bellow.

## Installation

This program has only been tested on OSX 10.11.6 with Matlab 2016a, but should work on every settings.

1. First set the path of your Matlab install trough the variable **MATLAB_ROOT** in **CMakeLists.txt**. For instance my matlab installation is /Applications/MATLAB_R2016a.app/.


2. Build and compile project using
```
cmake .
make
```

3. Add the Matlab binary folder to your path. For instance I use
```
export PATH=$PATH:/Applications/MATLAB_R2016a.app/bin
```
Otherwise you might get the error *matlab: Command not found*.

3. Finally run the executable
```
./matlab_from_cpp
```

## TO DO

- POO