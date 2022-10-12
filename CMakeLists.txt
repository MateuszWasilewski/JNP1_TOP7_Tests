cmake_minimum_required(VERSION 3.10)

project(Top7)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_definitions(-DTESTING)

FILE(GLOB InputTestFiles unit_tests/InputTests/*.cpp)

add_executable(
    Test
    ${InputTestFiles}
)
target_include_directories(Test PRIVATE 
  .
  unit_tests/InputTests
)

target_link_libraries(
    Test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Test)