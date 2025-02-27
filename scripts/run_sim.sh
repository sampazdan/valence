#!/bin/bash

# builds and runs a basic simulation file so I can mess around with shit

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

BUILD_DIR="${PROJECT_ROOT}/build"

cd "$PROJECT_ROOT"

cmake -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$BUILD_DIR" --clean-first
cmake --build "$BUILD_DIR"

"$BUILD_DIR/examples/basic_simulation"