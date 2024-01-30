cmake_minimum_required(VERSION 3.27)
project(gtest-mixin)

set(CMAKE_CXX_STANDARD 20)

################################
# GTest
################################
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

################################
# Resources
################################
add_subdirectory(res)

################################
# Unit tests
################################
add_subdirectory(mixin-fixture)
add_subdirectory(virtual-inheritance-fixture)
add_subdirectory(in-place-fixture)
