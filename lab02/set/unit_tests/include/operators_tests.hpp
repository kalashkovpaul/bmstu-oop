
#ifndef OPERATORS_TESTS_HPP_

#define OPERATORS_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(OperatorsTest, Assigment) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>(a);
    EXPECT_EQ(b, a);
}

TEST(OperatorsTest, SelfAssigment) {
    auto a = Set<int>{1, 2, 3, 4};
    a = a;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

TEST(OperatorsTest, AssigmentClearing) {
    auto a = Set<int>{1, 2, 3, 4};
    Set<int> b;
    b = a;
    b.clear();
    EXPECT_EQ(b, Set<int>());
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4}));
}

TEST(OperatorsTest, AddSet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{11, 12, 13, 14};
    a += b;
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 11, 12, 13, 14}));
}

TEST(OperatorsTest, SumSet) {
    auto a = Set<int>{1, 2, 3, 4};
    auto b = Set<int>{5, 6, 7, 8};
    EXPECT_EQ(a + b, (Set<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(OperatorsTest, StringifyEmpty) {
    auto a = Set<int>();
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "");
}

TEST(OperatorsTest, StringifyConstEmpty) {
    const auto a = Set<int>();
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "");
}

TEST(OperatorsTest, Stringify) {
    auto a = Set<int>{1, 2, 3, 4};
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1 2 3 4 ");
}

TEST(OperatorsTest, StringifyConst) {
    const auto a = Set<int>{1, 2, 3, 4};
    std::ostringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1 2 3 4 ");
}

#endif
