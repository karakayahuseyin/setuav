#!/bin/bash

if [ -f "lib/xfoil/build/src/xfoil" ]; then
    echo "Xfoil binaries already built"
    exit 0
fi

if [ ! -d "lib/xfoil" ]; then
    echo "Xfoil source not found"
    exit 1
fi

# build xfoil binaries
cd lib/xfoil
mkdir build
cd build
cmake ..
make
cd ../../..

if [ ! -f "lib/xfoil/build/src/xfoil" ]; then
    echo "Xfoil binaries not built successfully"
    exit 1
fi

echo "Xfoil binaries built successfully"