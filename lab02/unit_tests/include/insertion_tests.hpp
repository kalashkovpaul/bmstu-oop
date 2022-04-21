
#ifndef INSERTION_TESTS_HPP_

#define INSERTION_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(InsertTest, ToEmptySet) {
    auto a = Set<int>();
    auto v = 6;
    EXPECT_EQ(a.add(v), true);
    EXPECT_EQ(a, (Set<int>{6}));
}

TEST(InsertTest, ToEmptySetRValue) {
    auto a = Set<int>();
    EXPECT_EQ(a.add(6), true);
    EXPECT_EQ(a, (Set<int>{6}));
}

TEST(InsertTest, SingleToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto v = 6;
    EXPECT_EQ(a.add(v), true);
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(InsertTest, SingleToNonEmptyRValue) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(a.add(6), true);
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(InsertTest, MultipleToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    a.add({8, 9, 10});
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5, 8, 9, 10}));
}

TEST(InsertTest, MultipleRepeatedToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    a.add({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});
    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

TEST(InsertTest, MultipleRepeatedArrayToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};

    int * b = new int[13]{3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21};
    a.add(b, 13);
    delete[] b;

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

#endif
