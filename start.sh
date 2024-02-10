#!/bin/bash
 
rm -rf build
cmake -B build
cmake --build build --config Release
cd build && ./MyApp