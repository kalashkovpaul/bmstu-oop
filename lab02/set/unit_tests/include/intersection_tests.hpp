#ifndef INTERSECTION_TESTS_H_

#define INTERSECTION_TESTS_H_

#include <gtest/gtest.h>
#include "Set.h"


TEST(IntersectionTest, EmptySets) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a.intersect(b), (Set<int>()));
}

TEST(IntersectionTest, NonAndEmptySet) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = Set<int>();
    auto c = a.intersect(b);
    std::cout << c;
    EXPECT_EQ(a.intersect(b), (Set<int>()));
}

TEST(IntersectionTest, NonEmptySet) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = Set<int>{3, 4, 5, 6, 7};
    EXPECT_EQ(a.intersect(b), (Set<int>{3, 4, 5}));
}

TEST(IntersectionTest, EmptySetsOperator) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a & b, (Set<int>()));
}

TEST(IntersectionTest, NonAndEmptySetOperator) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = Set<int>();
    EXPECT_EQ(a & b, (Set<int>()));
}

TEST(IntersectionTest, NonEmptySetOperator) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = Set<int>{0, 3, 4, 5, 6, 7};
    EXPECT_EQ(a & b, (Set<int>{3, 4, 5}));
}

#endif
