cmake_minimum_required(VERSION 3.5)

add_library(transitionmodel_interface INTERFACE
)

add_library(tis::transitionmodel_interface ALIAS transitionmodel_interface)

target_include_directories(transitionmodel_interface
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/interface
)

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
        tis::transitionmodel_interface
	    types
)
 
EnableCoverage(transitionmodel)
 
add_subdirectory(test)
