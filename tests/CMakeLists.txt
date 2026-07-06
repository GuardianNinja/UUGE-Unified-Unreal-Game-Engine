enable_testing()

add_executable(UUGE_Tests
    tests/main.cpp
    tests/serialization/test_serialization.cpp
)

add_test(NAME UUGE_Tests COMMAND UUGE_Tests)
