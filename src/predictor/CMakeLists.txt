cmake_minimum_required(VERSION 3.5)

add_library(predictor
    ${CMAKE_CURRENT_LIST_DIR}/src/EkfPredictor.cpp
)

add_library(tis::predictor ALIAS predictor)

target_include_directories(predictor
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(predictor
    PUBLIC
        tis::transitionmodel_interface
	    types
        Eigen3::Eigen
)
  
EnableCoverage(predictor)

add_subdirectory(test)
