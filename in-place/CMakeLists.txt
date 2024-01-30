# Add test cpp file
add_executable( in-place-test
        file-test.cpp
        memory-test.cpp
        both-test.cpp
    )
# Link test executable against gtest & gtest_main
target_link_libraries(in-place-test PRIVATE GTest::gtest GTest::gtest_main)
# Add copy of file to target dir
add_dependencies(in-place-test copy-resources)

add_test(inPlaceTest in-place-test)
