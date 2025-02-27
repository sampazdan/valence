# Tests subdirectory
# Add your testing frameworks and test executables

enable_testing()

add_executable(unit_tests
    unit/test_ValenceState.cpp
    unit/test_ValenceGate.cpp
    # ...
)
target_link_libraries(unit_tests PRIVATE valence gtest_main)

add_test(NAME ValenceUnitTests COMMAND unit_tests)

# Add more test executables for integration/performance if needed
