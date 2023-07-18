@echo off

if not exist "build" (
  mkdir build
)

git submodule update --init --recursive
cd build
Cmake -G Ninja ..
ninja
cd bin
.\Starship.exe
