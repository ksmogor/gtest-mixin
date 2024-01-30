
#include "mixin-fixture.h"
#include "partial-fixtures/memory-fixture.h"

class MemoryTest : public MixinFixture<MemoryFixture>
{};

TEST_F(MemoryTest, ReadWriteMemory)
{
    std::string result;
    const std::string expected_res = "Hello from memory!";

    write_offset(expected_res, expected_res.size());
    read_offset(result, expected_res.size());

    ASSERT_EQ(result, expected_res);
}
