
#pragma once

/**
 * Recursive definition of wraping partial fixtures into one big Mix-In.
 */

#include <gtest/gtest.h>

template<template <typename> class T1, template <typename> class ...Ts>
struct MixinFixtureInner
{
    using type = T1<typename MixinFixtureInner<Ts ...>::type>;
};

template<template <typename> class T>
struct MixinFixtureInner<T>
{
    using type = T<testing::Test>;
};

template<template <typename> class ...Ts>
using MixinFixture = typename MixinFixtureInner<Ts...>::type;
