#include <iostream>

#include "gtest/gtest.h"

TEST(SampleTest, SampleTestCase)
{
    EXPECT_EQ(1, 1);
}

TEST(SampleTest, SampleTestCase2)
{
    EXPECT_EQ(1, 0);
}

TEST(SampleTest2, SampleTest2Case)
{
    EXPECT_EQ(1, 1);
}