#!/usr/bin/env bash
# Simple build script for Valence

mkdir -p build && cd build
cmake ..
make -j $(nproc)
