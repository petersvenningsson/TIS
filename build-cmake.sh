#! /bin/bash

mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug ..

echo "Running clang-format..."
cmake --build . -t format

echo "Building TIS..."
cmake --build .

echo "Running clang-tidy..."
cmake --build . -t linter

echo "Running tests..."
ctest . --rerun-failed --output-on-failure

echo "Building coverage report..."
cmake --build . -t coverage-unit-tests memcheck-unit-tests
