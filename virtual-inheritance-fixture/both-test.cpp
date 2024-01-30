
#include "PartialFixtures/MemoryFixture.h"
#include "PartialFixtures/FileFixture.h"

/**
 * With multi-inheritance we have to handle setup and teardown by hand.
 * Someone change order of those calls.
 *
 * But finally we have everything what selected classes offer to its child.
 */
class BothTest : public MemoryFixture, public FileFixture
{
    virtual void SetUp() override {
        MemoryFixture::SetUp();
        FileFixture::SetUp();
    }

    virtual void TearDown() override {
        // Should it be the same order as SetUp or not?
        // Answer: It depends what we want to achieve.
        FileFixture::TearDown();
        MemoryFixture::TearDown();
    }
};

TEST_F(BothTest, ReadMemoryFromFile)
{
    std::string result, line;
    const std::string expected_res = "Hello from test file!";

    file_stream.getline(mem_block, k_block_size);
    ASSERT_TRUE(file_stream.good());

    read_offset(result, file_stream.gcount() - 1); // null termination

    ASSERT_EQ(result, expected_res);
}
