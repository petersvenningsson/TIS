#! /bin/bash

echo "Building TIS..."

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake  --build .

echo "Running tests..."
ctest . --rerun-failed --output-on-failure

echo "Building coverage report..."
cmake  --build . -t coverage-unit-tests memcheck-unit-tests
