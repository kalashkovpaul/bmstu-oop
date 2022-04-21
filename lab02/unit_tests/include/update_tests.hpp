#include <gtest/gtest.h>
#include "Set.h"

TEST(UpdateTest, ToEmptySet) {
    auto a = Set<int>();
    auto v = 6;
    auto b = a.update(v);

    EXPECT_EQ(a, (Set<int>{}));
    EXPECT_EQ(b, (Set<int>{6}));
}

TEST(UpdateTest, ToEmptySetRValue) {
    auto a = Set<int>();
    auto b = a.update(6);

    EXPECT_EQ(a, (Set<int>{}));
    EXPECT_EQ(b, (Set<int>{6}));
}

TEST(UpdateTest, SingleToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto v = 6;
    auto b = a.update(v);

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(UpdateTest, SingleToNonEmptyRValue) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = a.update(6);

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(UpdateTest, MultipleToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = a.update({8, 9, 10});

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5, 8, 9, 10}));
}

TEST(UpdateTest, MultipleRepeatedToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};
    auto b = a.update({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

TEST(UpdateTest, MultipleRepeatedArrayToNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4, 5};

    int * b = new int[13]{3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21};
    auto c = a.update(b, 13);
    delete[] b;

    EXPECT_EQ(a, (Set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(c, (Set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}