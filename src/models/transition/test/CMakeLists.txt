add_executable(TestConstantVelocityTransitionModel
    ConstantVelocityTransitionModel_test.cpp
)

target_link_libraries(TestConstantVelocityTransitionModel
    PRIVATE
        tis::transitionmodel)

AddTests(TestConstantVelocityTransitionModel)
