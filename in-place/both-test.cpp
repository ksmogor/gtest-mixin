
#include <fstream>
#include "gtest/gtest.h"


class BothTest : public testing::Test
{
protected:
    static constexpr size_t k_block_size = 4096;
    char* mem_block;
    std::ifstream file_stream;

    BothTest() : mem_block(nullptr), file_stream("../res/test.txt")  {}

    virtual ~BothTest() {
        // This can go to TearDown and destructor
        file_stream.close();
    }

    virtual void SetUp() override {
        // Assert if file is opened correctly
        ASSERT_TRUE(file_stream.is_open());

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

TEST_F(BothTest, ReadMemoryFromFile)
{
    std::string result, line;
    const std::string expected_res = "Hello from test file!";

    file_stream.getline(mem_block, k_block_size);
    ASSERT_TRUE(file_stream.good());

    read_offset(result, file_stream.gcount() - 1); // null termination

    ASSERT_EQ(result, expected_res);
}
