add_executable(TestEkfPredictor
    EkfPredictor_test.cpp
)

target_link_libraries(TestEkfPredictor
    PRIVATE
        tis::predictor
        tis::transitionmodel
)

AddTests(TestEkfPredictor)
