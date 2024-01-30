
#include "mixin-fixture.h"
#include "partial-fixtures/memory-fixture.h"
#include "partial-fixtures/file-fixture.h"

/**
 * Right now this Mix-In should be treated as one big object.
 * We can derive from BothTest class normally and we still has one instance of testing::Test.
 *
 * Same as FileFixture<MemoryFixture<testing::Test>>
 */
class BothTest : public MixinFixture<FileFixture, MemoryFixture>
{};

TEST_F(BothTest, ReadMemoryFromFile)
{
    std::string result, line;
    const std::string expected_res = "Hello from test file!";

    file_stream.getline(mem_block, k_block_size);
    ASSERT_TRUE(file_stream.good());

    read_offset(result, file_stream.gcount() - 1); // null termination

    ASSERT_EQ(result, expected_res);
}
