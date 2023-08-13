cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
      ${CMAKE_CURRENT_LIST_DIR}/src/DataAssociator.cpp
      )

add_library(dataassociator OBJECT
           ${source_files}
           )

target_include_directories(dataassociator PUBLIC
                           ${include_paths}
                           )

target_link_libraries(dataassociator PUBLIC
	                 types
	                 hypothesiser
                     Eigen3::Eigen)

include(Coverage)
EnableCoverage(dataassociator)
