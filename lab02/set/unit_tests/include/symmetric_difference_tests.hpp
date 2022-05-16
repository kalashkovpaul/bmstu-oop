#ifndef SYMMETRIC_DIFFERENCE_TESTS_HPP_

#define SYMMETRIC_DIFFERENCE_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(SymmetricDifferenceTest, EmptySets) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a.symmetricDifference(b), Set<int>());
}

TEST(SymmetricDifferenceTest, EmptySetsOperator) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a ^ b, Set<int>());
}

TEST(SymmetricDifferenceTest, EmptySetsOperator2) {
    auto a = Set<int>();
    auto b = Set<int>();
    EXPECT_EQ(a ^= b, Set<int>());
}

TEST(SymmetricDifferenceTest, NonAndEmptySet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    EXPECT_EQ(a.symmetricDifference(b), (Set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonAndEmptySetOperator) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    EXPECT_EQ(a ^ b, (Set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonAndEmptySetOperator2) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>();
    EXPECT_EQ(a ^= b, (Set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, EmptyAndNonSet) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.symmetricDifference(b), (Set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, EmptyAndNonSetOperator) {
    auto a = Set<int>();
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^ b, (Set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonEmptySet) {
    auto a = Set<int>{3, 4, 5, 6, 7, 8};
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.symmetricDifference(b), (Set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator) {
    auto a = Set<int>{3, 4, 5, 6, 7, 8};
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^ b, (Set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator2) {
    auto a = Set<int>{3, 4, 5, 6, 7, 8};
    auto b = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^= b, (Set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySet_2) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a.symmetricDifference(b), (Set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator_2) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a ^ b, (Set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator_22) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a ^= b, (Set<int>{1, 2, 5, 6, 7, 8}));
}

#endif
