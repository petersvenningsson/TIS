cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
      ${CMAKE_CURRENT_LIST_DIR}/src/Hypothesiser.cpp
      )

add_library(hypothesiser OBJECT
           ${source_files}
           )

target_include_directories(hypothesiser PUBLIC
                           ${include_paths}
                           )

target_link_libraries(hypothesiser PUBLIC
	                 types
                     Eigen3::Eigen)

EnableCoverage(hypothesiser)
