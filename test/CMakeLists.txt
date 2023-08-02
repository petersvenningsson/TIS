cmake_minimum_required(VERSION 3.5)

include(Testing)

set(test_source
	${CMAKE_CURRENT_LIST_DIR}/Track/Density_test.cpp
	)

add_executable(unit-tests
			   ${test_source}
			   )

target_link_libraries(unit-tests PRIVATE
	                  Track
					  Eigen3::Eigen)

target_compile_definitions(Track PUBLIC
	-DUNIT_TEST)

AddTests(unit-tests)
EnableCoverage(unit-tests)
