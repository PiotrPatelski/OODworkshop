cmake_minimum_required(VERSION 3.16)
project(workshop CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_library(Stuff 
    src/MonopolyGame.cpp 
    src/Square.cpp)
target_include_directories(Stuff PUBLIC include)

add_executable(workshop src/main.cpp)
target_link_libraries(workshop Stuff)
target_compile_features(workshop PUBLIC cxx_std_17)

add_executable(tests src/sampleTests.cpp mocks/ExampleMock.hpp)
target_link_libraries(tests
    gtest
    gmock
    gtest_main
    Stuff)
target_compile_features(tests PUBLIC cxx_std_17)
target_include_directories(tests PUBLIC include mocks)
target_compile_options(tests PUBLIC -Wall -Wextra -pedantic -Werror)

add_custom_target(run_tests COMMAND ./tests DEPENDS tests)

enable_testing()

add_test(
    NAME allTests
    COMMAND tests
)