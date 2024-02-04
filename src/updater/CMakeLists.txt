cmake_minimum_required(VERSION 3.5)

add_library(updater
    ${CMAKE_CURRENT_LIST_DIR}/src/EkfUpdater.cpp
)

add_library(tis::updater ALIAS updater)

target_include_directories(updater
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(updater
    PUBLIC
        tis::measurementmodel_interface
	    types
        Eigen3::Eigen
)
  
EnableCoverage(updater)
