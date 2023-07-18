@echo off

if not exist "build" (
  mkdir build
)

cd build
cmake ..
cmake --build . --config Release
cd Release
.\Starship.exe
cd .. 
cd ..