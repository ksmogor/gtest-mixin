
#pragma once

#include <gtest/gtest.h>

class MemoryFixture : virtual public testing::Test
{
protected:
    static constexpr size_t k_block_size = 4096;
    char* mem_block;

    MemoryFixture();
    virtual ~MemoryFixture() noexcept;

    virtual void SetUp() override;
    virtual void TearDown() override;

    void write_offset(const std::string& data, size_t size, size_t offset = 0);
    void read_offset(std::string& output, size_t size, size_t offset = 0);
};
