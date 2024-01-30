# Add test cpp file
add_executable( mixin-fixture-test
        partial-fixtures/file-fixture.h
        partial-fixtures/memory-fixture.h
        mixin-fixture.h
        file-test.cpp
        memory-test.cpp
        both-test.cpp
    )
# Link test executable against gtest & gtest_main
target_link_libraries(mixin-fixture-test GTest::gtest GTest::gtest_main)
# Add copy of file to target dir
add_dependencies(mixin-fixture-test copy-resources)

add_test(mixinFixtureTest mixin-fixture-test )
