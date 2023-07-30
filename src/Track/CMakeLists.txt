cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
  ${CMAKE_CURRENT_LIST_DIR}/src/Density.cpp
    )

add_library(Track OBJECT
           ${source_files}
           )

target_include_directories(Track PUBLIC
                           ${include_paths}
                           )

target_link_libraries(Track PUBLIC
	                  Eigen3::Eigen)

EnableCoverage(Track)
