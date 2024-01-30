# Add test cpp file
add_executable( virt-inheritance-fixture-test
        PartialFixtures/FileFixture.cpp PartialFixtures/FileFixture.h
        PartialFixtures/MemoryFixture.cpp PartialFixtures/MemoryFixture.h
        file-test.cpp
        memory-test.cpp
        both-test.cpp
)
# Link test executable against gtest & gtest_main
target_link_libraries(virt-inheritance-fixture-test GTest::gtest GTest::gtest_main)
# Add copy of file to target dir
add_dependencies(virt-inheritance-fixture-test copy-resources)

add_test(virtualInheritanceFixtureTest virt-inheritance-fixture-test )
