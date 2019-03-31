add_executable(tests
    testMain.cpp
    testFoo.cpp

    trompeloeil_catch.h
)

target_include_directories(tests PRIVATE ${CONAN_INCLUDE_DIRS_TROMPELOEIL})
target_link_libraries(tests PRIVATE
    Catch2::Catch2
    myLib
)

#target_compile_definitions(tests PRIVATE TROMPELOEIL_USER_DEFINED_COMPILE_TIME_REPORTER)

catch_discover_tests(tests)
