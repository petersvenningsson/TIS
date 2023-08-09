cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
    ${CMAKE_CURRENT_LIST_DIR}/src/Hypothesis.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Detection.cpp
    )

add_library(types OBJECT
           ${source_files}
           )

target_include_directories(types PUBLIC
                           ${include_paths}
                           )

target_link_libraries(types PUBLIC
	                  track
	                  Eigen3::Eigen)

include(Coverage)
EnableCoverage(types)
