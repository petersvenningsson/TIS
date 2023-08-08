cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
      ${CMAKE_CURRENT_LIST_DIR}/src/ConstantVelocityTransitionModel.cpp
      ${CMAKE_CURRENT_LIST_DIR}/src/LinearGaussianMeasurementModel.cpp
      )

add_library(models OBJECT
           ${source_files}
           )

target_include_directories(models PUBLIC
                           ${include_paths}
                           )

target_link_libraries(models PUBLIC
	                  Eigen3::Eigen)

include(Coverage)
EnableCoverage(models)
