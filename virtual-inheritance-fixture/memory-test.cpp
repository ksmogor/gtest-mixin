
#include "PartialFixtures/MemoryFixture.h"

class MemoryTest : public MemoryFixture
{};

TEST_F(MemoryTest, ReadWriteMemory)
{
    std::string result;
    const std::string expected_res = "Hello from memory!";

    write_offset(expected_res, expected_res.size());
    read_offset(result, expected_res.size());

    ASSERT_EQ(result, expected_res);
}
