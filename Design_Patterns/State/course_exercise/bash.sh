#!/bin/bash

rm -fr out/

cmake -S . -B out/build/
cd out/build/
make

# ./state.exe

#run server and client:
./state.exe
