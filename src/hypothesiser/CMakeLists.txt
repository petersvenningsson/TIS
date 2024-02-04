cmake_minimum_required(VERSION 3.5)

add_library(hypothesiser_interface
    ${CMAKE_CURRENT_LIST_DIR}/src/Hypothesis.cpp
)

add_library(tis::hypothesiser_interface ALIAS hypothesiser_interface)

target_include_directories(hypothesiser_interface
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/interface
)

target_link_libraries(hypothesiser_interface
    PUBLIC
        types)

add_library(hypothesiser
    ${CMAKE_CURRENT_LIST_DIR}/src/Hypothesiser.cpp
)

add_library(tis::hypothesiser ALIAS hypothesiser)

target_include_directories(hypothesiser
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(hypothesiser
    PUBLIC
        tis::hypothesiser_interface
        types
        Eigen3::Eigen
)

add_subdirectory(test)

EnableCoverage(hypothesiser)
