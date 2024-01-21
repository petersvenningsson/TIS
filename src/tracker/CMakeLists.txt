cmake_minimum_required(VERSION 3.5)

set(include_paths
  ${CMAKE_CURRENT_LIST_DIR}/include
    )

set(source_files
  ${CMAKE_CURRENT_LIST_DIR}/src/Tracker.cpp
    )

add_library(tracker OBJECT
           ${source_files}
           )

target_include_directories(tracker PUBLIC
                           ${include_paths}
                           )

target_link_libraries(tracker PUBLIC
                      types
                      dataassociator
                      hypothesiser 
	                  Eigen3::Eigen)

EnableCoverage(tracker)
