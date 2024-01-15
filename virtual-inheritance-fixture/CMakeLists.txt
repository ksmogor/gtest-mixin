# Add test cpp file
add_executable( virt-inheritance-fixture-test
        StringFixture.cpp StringFixture.h
        VectorFixture.cpp VectorFixture.h
        virt-inheritance-test.cpp
)
# Link test executable against gtest & gtest_main
target_link_libraries(virt-inheritance-fixture-test gtest gtest_main)
add_test(virtualInheritanceFixtureTest virt-inheritance-fixture-test )