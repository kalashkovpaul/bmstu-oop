
#ifndef ERASE_TESTS_HPP_

#define ERASE_TESTS_HPP_


#include <gtest/gtest.h>
#include "Set.h"

TEST(EraseTest, Empty) {
    auto b = Set<int>{};
    b.erase(5);
    EXPECT_EQ(b.isEmpty(), true);
}

TEST(EraseTest, NonEmptyIncorrectConst) {
    auto b = Set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(10);
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

TEST(EraseTest, NonEmptyCorrect) {
    auto b = Set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(5);
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 9, 12, 21}));
}

TEST(EraseTest, NonEmptyCorrectConst) {
    auto b = Set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(5);
    EXPECT_EQ(b, (Set<int>{1, 2, 3, 4, 9, 12, 21}));
}

#endif
