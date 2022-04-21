#ifndef COMBINING_TESTS_HPP_

#define COMBINING_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(CombineTest, EmptyWithSet) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    auto t = a.unite(b);
    EXPECT_EQ(t, (Set<int>{1, 2, 3, 4}));
}

TEST(CombineTest, EmptyWithSetOperator) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    auto t = a | b;
    EXPECT_EQ(t, (Set<int>{1, 2, 3, 4}));
}

TEST(CombineTest, EmptyWithSetOperator2) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    a |= b;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}


#endif
