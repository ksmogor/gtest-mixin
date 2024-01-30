
#include "MemoryFixture.h"

MemoryFixture::MemoryFixture() : mem_block(nullptr) { }

MemoryFixture::~MemoryFixture() noexcept {
        // Nothing to do
}

void MemoryFixture::SetUp() {
    // It can raise std::bad_alloc, so it cannot be used inside constructor
    mem_block = new char[k_block_size];
    ASSERT_TRUE(mem_block);
}

void MemoryFixture::TearDown() {
    // This can go to TearDown and destructor
    if (mem_block)
        delete [] mem_block;
}

void MemoryFixture::write_offset(const std::string &data, size_t size, size_t offset) {
    for (size_t i = 0; i < size; ++i)
        mem_block[i + offset] = data[i];
}

void MemoryFixture::read_offset(std::string &output, size_t size, size_t offset) {
    output.resize(size);
    for (size_t i = 0; i < size; ++i)
        output[i] = mem_block[i + offset];
}
