if [ ! -d "build" ]; then
  mkdir build
fi

cd build
cmake ..
cmake --build . --config Release
cd Release
./Galaga
cd ..
cd ..