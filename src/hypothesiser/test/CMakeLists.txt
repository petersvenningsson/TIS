add_executable(TestHypothesiser
    Hypothesiser_test.cpp
)

target_link_libraries(TestHypothesiser
    PRIVATE
        tis::hypothesiser
)

AddTests(TestHypothesiser)
