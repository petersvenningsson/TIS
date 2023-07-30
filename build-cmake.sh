#! /bin/bash

echo "Building TIS..."

mkdir -p build
cd build
cmake ..
cmake --build .

echo "Running tests..."
ctest . --rerun-failed --output-on-failure
