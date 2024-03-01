#include "stack.h"
#include "gtest/gtest.h"

TEST(Stack, DefaultConstructor) {
    Stack<int> stack;
    EXPECT_EQ(stack.empty(), true);
    EXPECT_EQ(stack.size, 0);
    EXPECT_THROW(stack.pop(), std::runtime_error);
}

TEST(Stack, CopyConstructor) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2(stack1);
    EXPECT_EQ(stack2.empty(), false);
    EXPECT_EQ(stack2.size, 3);
    EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, Double) {
    Stack<double> stack;
    stack.push(3.14);
    stack.push(2.71);
    stack.push(1.618);

    EXPECT_EQ(stack.top(), 1.618);
    stack.pop();
    EXPECT_EQ(stack.top(), 2.71);
    stack.pop();
    EXPECT_EQ(stack.top(), 3.14);
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, String) {
    Stack<std::string> stack;
    stack.push("hello");
    stack.push("world");
    stack.push("!");

    EXPECT_EQ(stack.top(), "!");
    stack.pop();
    EXPECT_EQ(stack.top(), "world");
    stack.pop();
    EXPECT_EQ(stack.top(), "hello");
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(Stack, CopyAssignmentOperator) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2;
    stack2 = stack1;
    EXPECT_EQ(stack2.empty(), false);
    EXPECT_EQ(stack2.size, 3);
    EXPECT_EQ(stack2.top(), 3);
}

TEST(Stack, MoveConstructor) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2(std::move(stack1));
    EXPECT_EQ(stack1.empty(), true);
    EXPECT_EQ(stack1.size, 0);
    EXPECT_EQ(stack2.empty(), false);
    EXPECT_EQ(stack2.size, 3);
    EXPECT_EQ(stack2.top(), 3);
}

TEST(Stack, MoveAssignmentOperator) {
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2;
    stack2 = std::move(stack1);
    EXPECT_EQ(stack1.empty(), true);
    EXPECT_EQ(stack1.size, 0);
    EXPECT_EQ(stack2.empty(), false);
    EXPECT_EQ(stack2.size, 3);
    EXPECT_EQ(stack2.top(), 3);
}

TEST(Stack, Destructor) {
    auto *stack = new Stack<int>();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    delete stack;
}

TEST(Stack, Push) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size, 3);
    EXPECT_EQ(stack.top(), 3);
}

TEST(Stack, Pop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    EXPECT_EQ(stack.empty(), false);
    EXPECT_EQ(stack.size, 2);
    EXPECT_EQ(stack.top(), 2);
}

TEST(Stack, Top) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
}

TEST(Stack, Empty) {
    Stack<int> stack;
    EXPECT_EQ(stack.empty(), true);
    stack.push(1);
    EXPECT_EQ(stack.empty(), false);
}