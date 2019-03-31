add_executable(tests
    testMain.cpp
    testFoo.cpp
)

target_include_directories(tests PRIVATE ${CONAN_INCLUDE_DIRS_TROMPELOEIL})
target_link_libraries(tests PRIVATE
    Catch2::Catch2
    myLib
)

catch_discover_tests(tests)
