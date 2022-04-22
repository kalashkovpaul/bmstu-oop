
#ifndef LOOKUP_TESTS_H_

#define LOOKUP_TESTS_H_

#include <gtest/gtest.h>
#include "Set.h"


TEST(LookupTest, EmptySet) {
    auto a = Set<int>();
    EXPECT_EQ(a.isEmpty(), true);
}

TEST(LookupTest, EmptySetNonEmpty) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.isEmpty(), false);
}

TEST(LookupTest, EmptySetCount) {
    auto a = Set<int>();
    EXPECT_EQ(a.capacity(), 0);
}

TEST(LookupTest, NonEmptySetCount) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.capacity(), 4);
}

#endif
