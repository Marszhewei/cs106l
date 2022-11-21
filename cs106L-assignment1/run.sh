#!/bin/bash

echo "start build"
rm main
mkdir build && cd build
cmake .. && make
mv main ../ && cd .. && rm -rf build
clear && ./main