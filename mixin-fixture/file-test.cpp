
#include "mixin-fixture.h"
#include "partial-fixtures/file-fixture.h"

class FileTest : public MixinFixture<FileFixture>
{};

TEST_F(FileTest, ReadFile)
{
    std::string result;
    const std::string expected_res = "Hello from test file!";

    std::getline(file_stream, result);
    ASSERT_TRUE(file_stream.good());

    ASSERT_EQ(result, expected_res);
}
