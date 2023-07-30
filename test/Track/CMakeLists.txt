add_executable(Density_test Density_test.cpp)
target_link_libraries(Density_test PRIVATE
	                  Track
					  Eigen3::Eigen)

AddTests(Density_test)
