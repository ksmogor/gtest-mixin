
#include "gtest/gtest.h"


class MemoryTest : public testing::Test
{
protected:
    static constexpr size_t k_block_size = 4096;
    char* mem_block;

    MemoryTest() : mem_block(nullptr) {}

    virtual ~MemoryTest() {
        // Nothing to do
    }

    virtual void SetUp() override {
        // It can raise std::bad_alloc, so it cannot be used inside constructor
        mem_block = new char[k_block_size];
        ASSERT_TRUE(mem_block);
    }

    virtual void TearDown() override {
        // This can go to TearDown and destructor
        if (mem_block)
            delete [] mem_block;
    }
    
    void write_offset(const std::string& data, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
            mem_block[i] = data[i];
    }

    void read_offset(std::string& output, size_t size)
    {
        output.resize(size);
        for (size_t i = 0; i < size; ++i)
            output[i] = mem_block[i];
    }
};

TEST_F(MemoryTest, ReadWriteMemory)
{
    std::string result;
    const std::string expected_res = "Hello from memory!";

    write_offset(expected_res, expected_res.size());
    read_offset(result, expected_res.size());

    ASSERT_EQ(result, expected_res);
}
