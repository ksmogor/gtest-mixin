
#include <fstream>
#include "gtest/gtest.h"


class FileTest : public testing::Test
{
protected:
    std::ifstream file_stream;

    // ifstream::open cannot throw exception, so it's safe to call it inside constructor
    FileTest() : file_stream("../res/test.txt") {}

    virtual ~FileTest() {
        // This can go to TearDown and destructor
        file_stream.close();
    }

    virtual void SetUp() override {
        // Assert if file is opened correctly
        ASSERT_TRUE(file_stream.is_open());
    }

    virtual void TearDown() override {
        // Nothing to do
    }
};

TEST_F(FileTest, ReadFile)
{
    std::string result;
    const std::string expected_res = "Hello from test file!";

    std::getline(file_stream, result);

    ASSERT_EQ(result, expected_res);
}
