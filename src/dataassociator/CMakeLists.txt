cmake_minimum_required(VERSION 3.5)

add_library(dataassociator_interface
    ${CMAKE_CURRENT_LIST_DIR}/src/JointHypothesis.cpp
)

add_library(tis::dataassociator_interface ALIAS dataassociator_interface)

target_include_directories(dataassociator_interface
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/interface
)

target_link_libraries(dataassociator_interface
    PUBLIC
        types)

add_library(dataassociator
        ${CMAKE_CURRENT_LIST_DIR}/src/DataAssociator.cpp
)

add_library(tis::dataassociator ALIAS dataassociator)

target_include_directories(dataassociator
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(dataassociator
    PUBLIC
        tis::dataassociator_interface
	    types
	    hypothesiser
        Eigen3::Eigen
)
 
EnableCoverage(dataassociator)

add_subdirectory(test)
