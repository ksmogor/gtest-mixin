//
// Created by ksm on 15/01/24.
//

#ifndef MIXIN_TEST_VECTORFIXTURE_H
#define MIXIN_TEST_VECTORFIXTURE_H

#include <vector>
#include <gtest/gtest.h>

class VectorFixture : virtual public testing::Test
{
public:
    std::vector<int> vector_fixture_member = {1, 2, 3, 4};
};

#endif //MIXIN_TEST_VECTORFIXTURE_H
