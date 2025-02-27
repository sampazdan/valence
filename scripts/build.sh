#!/bin/bash
set -e

mkdir -p ../build
cd ../build

# detect num cores
if command -v nproc &> /dev/null; then
    # Linux
    NUM_CORES=$(nproc)
elif command -v sysctl &> /dev/null; then
    # macOS
    NUM_CORES=$(sysctl -n hw.ncpu)
else
    NUM_CORES=2
fi

cmake ..

make -j${NUM_CORES}
