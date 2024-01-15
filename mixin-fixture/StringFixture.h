//
// Created by ksm on 15/01/24.
//

#ifndef MIXIN_TEST_STRINGFIXTURE_H
#define MIXIN_TEST_STRINGFIXTURE_H

#include <string>

template <typename Base>
class StringFixture : public Base
{
public:
    std::string string_fixture_member = "mixin-string";
};

#endif //MIXIN_TEST_STRINGFIXTURE_H
