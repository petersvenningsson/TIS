# Tracking is Simple (TIS)

Open source target tracking library for multi-object tracking focusing on ease-of-use.

### Motivation

Current open source projects for target tracking appropriate for embedded platforms are typically limited to one tracking algorithm without a clear API.

Open source projects like [StoneSoup](https://github.com/dstl/Stone-Soup) have succesfully implemented a easy to use and customizable API for target tracking applications. However it is implemented in Python and not appropriate for embedded applications.

TIS aims to fill this gap by providing an open source C++ library for target tracking suitable for embedded applications.


### Prerequisities

```
C++ 17
CMake 3.20
```

## Targets

1. `format` Automatic formatting. Google C++ styleguide.
2. `linter` Clang-tidy static analysis.
3. `unit-tests` Build unit tests.
4. `coverage-unit-tests` Generate a coverage report from gcov.
5. `memcheck-unit-tests` Generate a Memcheck report from Valgrind.
6. `doc` Generate the code API documentation.

See
```
./build-cmake.sh
```
for examples on how to build the targets.

## License

This project is licensed under the **BSD License** - see the [LICENSE.md](LICENSE.md) file for details.
