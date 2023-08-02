cmake_minimum_required(VERSION 3.20.0)
project(TIS VERSION 0.0.1 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(ExternalDependencies)
include(GenerateDocumentation)
include(Testing)
include(Format)
include(Linter)
include(Config)

add_subdirectory(src)
add_subdirectory(test)

