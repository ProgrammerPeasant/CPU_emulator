#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

    stack.pop();

    std::cout << "Top element of the stack: " << stack.top() << std::endl;

    stack.push(4);
    stack.push(5);

    std::cout << "Contents of the stack: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}