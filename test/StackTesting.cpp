#include "Stack.h" // Include your Stack header file
#include "gtest/gtest.h"

// Test fixture for the Stack class
class StackTest : public ::testing::Test {
protected:
    // Per-test setup
    void SetUp() override {
        // Code that will be executed before each test
    }

    // Per-test cleanup
    void TearDown() override {
        // Code that will be executed after each test
    }

    // Declare variables needed for testing
    Stack<int> intStack;
};

// Test case to check if the stack is empty after construction
TEST_F(StackTest, IsEmptyAfterConstruction) {
EXPECT_TRUE(intStack.empty());
}

// Test case to check if pushing elements increases the size
TEST_F(StackTest, PushIncreasesSize) {
intStack.push(5);
EXPECT_FALSE(intStack.empty());
}

// Test case to check if popping elements decreases the size
TEST_F(StackTest, PopDecreasesSize) {
intStack.push(10);
intStack.pop();
EXPECT_TRUE(intStack.empty());
}

// Test case to check if the top element is returned correctly
TEST_F(StackTest, TopReturnsCorrectElement) {
intStack.push(15);
EXPECT_EQ(intStack.top(), 15);
}

// Test case to check if the stack is empty after popping all elements
TEST_F(StackTest, IsEmptyAfterPoppingAll) {
intStack.push(20);
intStack.pop();
EXPECT_TRUE(intStack.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
