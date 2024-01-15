//
// Created by ksm on 15/01/24.
//

#include <gtest/gtest.h>
#include "StringFixture.h"
#include "VectorFixture.h"

class VirtInheritanceTest : public StringFixture, public VectorFixture
{
protected:
    int mixin_member = 10;
};

TEST_F(VirtInheritanceTest, SampleTest)
{
std::cout << "Virtual inheritance test body" << std::endl;
ASSERT_EQ(mixin_member, 10);
ASSERT_EQ(string_fixture_member, "mixin-string");
ASSERT_EQ(vector_fixture_member.size(), 4);
}