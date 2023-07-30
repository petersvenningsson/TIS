#! /bin/bash

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug

echo "Running clang-format..."
cmake  --build . -t format

echo "Building TIS..."
cmake  --build .

echo "Running tests..."
ctest . --rerun-failed --output-on-failure

echo "Building coverage report..."
cmake  --build . -t coverage-unit-tests memcheck-unit-tests
