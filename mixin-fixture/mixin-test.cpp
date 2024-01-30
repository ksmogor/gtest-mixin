
#include "gtest/gtest.h"
#include "VectorFixture.h"
#include "StringFixture.h"

typedef StringFixture<VectorFixture<testing::Test>> MixinStringVectorFixture;

template<template <typename> class T1, template <typename> class ...Ts>
struct MixinFixture
{
    using type = T1<typename MixinFixture<Ts ...>::type>;
};

template<template <typename> class T>
struct MixinFixture<T>
{
    using type = T<testing::Test>;
};

template<template <typename> class ...Ts>
using MixinFixtureType = typename MixinFixture<Ts...>::type;

//class MixinTest : public MixinStringVectorFixture
class MixinTest : public MixinFixtureType<StringFixture, VectorFixture>
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
