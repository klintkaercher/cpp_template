#include <gtest/gtest.h>

#include "lib.h"

// // Declare function we're testing
// int add(int a, int b);

// Define test
TEST(AdditionTest, BasicAddition) {
    EXPECT_EQ(helper::add(1, 2), 3);
    EXPECT_EQ(helper::add(-1, 1), 0);
    EXPECT_NE(helper::add(2, 2), 5);
}
