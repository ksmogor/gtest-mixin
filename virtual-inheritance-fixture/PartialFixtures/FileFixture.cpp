
#include "FileFixture.h"

// ifstream::open cannot throw exception, so it's safe to call it inside constructor
FileFixture::FileFixture() : file_stream("../res/test.txt") {}

FileFixture::~FileFixture() noexcept {
    // This can go to TearDown and destructor
    file_stream.close();
}

void FileFixture::SetUp()  {
    // Assert if file is opened correctly
    ASSERT_TRUE(file_stream.is_open());
}

void FileFixture::TearDown() {
    // Nothing to do
}
