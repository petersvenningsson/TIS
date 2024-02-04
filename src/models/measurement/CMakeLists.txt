cmake_minimum_required(VERSION 3.5)

add_library(measurementmodel
    ${CMAKE_CURRENT_LIST_DIR}/src/LinearGaussianMeasurementModel.cpp
)

add_library(tis::measurementmodel ALIAS measurementmodel)

target_include_directories(measurementmodel
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(measurementmodel
    PUBLIC
	    types
)
  
EnableCoverage(measurementmodel)

add_subdirectory(test)
