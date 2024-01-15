# Add test cpp file
add_executable( mixin-fixture-test
        StringFixture.cpp StringFixture.h
        VectorFixture.cpp VectorFixture.h
        mixin-test.cpp
    )
# Link test executable against gtest & gtest_main
target_link_libraries(mixin-fixture-test gtest gtest_main)
add_test(mixinFixtureTest mixin-fixture-test )