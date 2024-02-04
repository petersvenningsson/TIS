add_executable(TestLinearGaussianMeasurementModel
    LinearGaussianMeasurementModel_test.cpp
)

target_link_libraries(TestLinearGaussianMeasurementModel
    PRIVATE
        tis::measurementmodel)

AddTests(TestLinearGaussianMeasurementModel)
