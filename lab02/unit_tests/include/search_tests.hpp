
#ifndef SEARCH_TESTS_HPP_

#define SEARCH_TESTS_HPP_

#include <gtest/gtest.h>
#include "Set.h"

TEST(SearchTest, Found) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_NE(a.find(4), a.end());
}

TEST(SearchTest, NotFound) {
    auto a = Set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.find(5), a.end());
}

#endif
