
#pragma once

#include <gtest/gtest.h>
#include <fstream>

class FileFixture : virtual public testing::Test
{
protected:
    std::ifstream file_stream;

    FileFixture();
    virtual ~FileFixture() noexcept;

    virtual void SetUp() override;
    virtual void TearDown() override;
};
