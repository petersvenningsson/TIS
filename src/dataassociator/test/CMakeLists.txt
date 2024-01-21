add_executable(TestDataAssociator
    DataAssociator_test.cpp
)

target_link_libraries(TestDataAssociator
    PRIVATE
        tis::dataassociator)

AddTests(TestDataAssociator)
