cmake_minimum_required(VERSION 3.5)

include(Testing)

set(test_source
	${CMAKE_CURRENT_LIST_DIR}/types/Density_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/models/LinearGaussianMeasurementModel_test.cpp
    ${CMAKE_CURRENT_LIST_DIR}/models/ConstantVelocityTransitionModel_test.cpp
	)

add_executable(unit-tests
			   ${test_source}
			   )

target_link_libraries(unit-tests PRIVATE
	                  types
                      models 
					  Eigen3::Eigen)

target_compile_definitions(types PUBLIC
	-DUNIT_TEST)

AddTests(unit-tests)
EnableCoverage(unit-tests)
