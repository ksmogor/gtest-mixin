
#pragma once

#include <gtest/gtest.h>
#include <fstream>

template <typename Base>
class FileFixture : public Base
{
private:
    using base_t = Base;

protected:
    std::ifstream file_stream;

    // ifstream::open cannot throw exception, so it's safe to call it inside constructor
    FileFixture() : file_stream("../res/test.txt") {}
    virtual ~FileFixture() noexcept{
        // This can go to TearDown and destructor
        file_stream.close();
    }

    virtual void SetUp() override  {
        // Remember to call SetUp recursively.
        // To mimic order of constructors just call it at the beginning of the function.
        base_t::SetUp();

        // Assert if file is opened correctly
        ASSERT_TRUE(file_stream.is_open());
    }

    virtual void TearDown() override {
        // Some code goes here...

        // Remember to call TearDown recursively.
        // To mimic order of destructors just call it at the end of the function.
        base_t::TearDown();
    }
};
