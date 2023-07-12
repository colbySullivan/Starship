@echo off

if not exist "build" (
  mkdir build
)

cd build
Cmake -G Ninja ..
ninja
cd bin
.\Galaga.exe
