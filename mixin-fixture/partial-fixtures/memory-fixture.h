
#pragma once

#include <gtest/gtest.h>

template <typename Base>
class MemoryFixture : public Base
{
private:
    using base_t = Base;

protected:
    static constexpr size_t k_block_size = 4096;
    char* mem_block;

    MemoryFixture() : mem_block(nullptr) { }
    virtual ~MemoryFixture() noexcept{
        // Nothing to do
    }

    virtual void SetUp() override{
        // Remember to call SetUp recursively.
        // To mimic order of constructors just call it at the beginning of the function.
        base_t::SetUp();

        // It can raise std::bad_alloc, so it cannot be used inside constructor
        mem_block = new char[k_block_size];
        ASSERT_TRUE(mem_block);
    }
    virtual void TearDown() override{
        // This can go to TearDown and destructor
        if (mem_block)
            delete [] mem_block;

        // Remember to call TearDown recursively.
        // To mimic order of destructors just call it at the end of the function.
        base_t::TearDown();
    }

    void write_offset(const std::string& data, size_t size, size_t offset = 0) {
        for (size_t i = 0; i < size; ++i)
            mem_block[i + offset] = data[i];
    }

    void read_offset(std::string& output, size_t size, size_t offset = 0) {
        output.resize(size);
        for (size_t i = 0; i < size; ++i)
            output[i] = mem_block[i + offset];
    }
};
