add_executable(TestEkfUpdator
    EkfUpdator_test.cpp
)

target_link_libraries(TestEkfUpdator
    PRIVATE
        tis::updater
        tis::measurementmodel
)

AddTests(TestEkfUpdator)
