
#ifndef EQUALITY_TESTS_HPP_

#define EQUALITY_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(EqualTest, EmptyEqual) {
    Set<int> a;
    EXPECT_EQ(a, Set<int>());
}

TEST(EqualTest, NonEmptyEqual) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

TEST(EqualTest, EmptyNonEqual) {
    Set<int> a;
    EXPECT_NE(a, (Set<int>{1}));
}

TEST(EqualTest, EmptyNotEqual) {
    Set<int> a{1};
    Set<int> b;
    bool equal = (a == b);
    EXPECT_EQ(equal, false);
}

TEST(EqualTest, NonEmptyNonEqual) {
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_NE(b, Set<int>());
}

TEST(EqualTest, NonEmptyNotEqual) {
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ((Set<int>{5, 6, 7, 8} == b), false);
}

#endif
