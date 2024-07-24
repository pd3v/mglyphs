#!/bin/bash

mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release -DGIT_ACTION=ON ..

make

# rm -r CMakeFiles
# rm *.cmake
# rm CMakeCache.txt
# rm Makefile

