//
// Created by ksm on 15/01/24.
//

#ifndef MIXIN_TEST_STRINGFIXTURE_H
#define MIXIN_TEST_STRINGFIXTURE_H

#include <string>
#include <gtest/gtest.h>

class StringFixture : virtual public testing::Test
{
public:
    std::string string_fixture_member = "mixin-string";
};

#endif //MIXIN_TEST_STRINGFIXTURE_H
