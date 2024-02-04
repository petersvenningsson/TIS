cmake_minimum_required(VERSION 3.5)

add_library(transitionmodel
    ${CMAKE_CURRENT_LIST_DIR}/src/ConstantVelocityTransitionModel.cpp
)

add_library(tis::transitionmodel ALIAS transitionmodel)

target_include_directories(transitionmodel
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(transitionmodel
    PUBLIC
	    types
)
 
EnableCoverage(transitionmodel)

add_subdirectory(test)
