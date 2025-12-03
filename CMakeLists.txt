cmake_minimum_required(VERSION 4.0)
project(aoc25)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(aoc25lib SHARED
        src/day_runner.cpp
        include/day_runner.h
        include/abstract_day.h
        src/days/day_one.cpp
        include/days/day_one.h
        include/utils/string_utils.h
        include/days/day_two.h
        src/days/day_two.cpp
)

target_include_directories(aoc25lib PUBLIC include)

add_executable(aoc25 src/main.cpp)
target_link_libraries(aoc25 PRIVATE aoc25lib)

enable_testing()
add_executable(aoc25test
        test/day_runner_test.cpp
        test/days/day_one_test.cpp
        test/days/day_two_test.cpp)
target_link_libraries(
        aoc25test
        aoc25lib
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_Tests(aoc25test)
