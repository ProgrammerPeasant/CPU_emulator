#include "stack.h"
#include "gtest/gtest.h"

TEST(StackConstructor, default_constructor) {
    Stack<int> a;
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size, 0);
    EXPECT_THROW(a.top(), std::runtime_error);
}