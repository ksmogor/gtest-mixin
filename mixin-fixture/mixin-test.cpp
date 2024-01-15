//
// Created by ksm on 15/01/24.
//


#include "gtest/gtest.h"
#include "VectorFixture.h"
#include "StringFixture.h"

typedef StringFixture<VectorFixture<testing::Test>> MixinStringVectorFixture;

class MixinTest : public MixinStringVectorFixture
{
protected:
    int mixin_member = 10;
};

TEST_F(MixinTest, SampleTest)
{
    std::cout << "Mixin test body" << std::endl;
    ASSERT_EQ(mixin_member, 10);
    ASSERT_EQ(string_fixture_member, "mixin-string");
    ASSERT_EQ(vector_fixture_member.size(), 4);
}