cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

  set(source_files
  ${CMAKE_CURRENT_LIST_DIR}/src/Density.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/Track.cpp
    )

add_library(track OBJECT
           ${source_files}
           )

target_include_directories(track PUBLIC
                           ${include_paths}
                           )

target_link_libraries(track PUBLIC
	                  Eigen3::Eigen)

include(Coverage)
EnableCoverage(track)
