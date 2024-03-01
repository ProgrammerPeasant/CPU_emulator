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

    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    Stack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    doubleStack.push(1.618);

    Stack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");
    stringStack.push("!");

    std::cout << "Contents of the stack: ";
    while (!stringStack.empty()) {
        std::cout << stringStack.top() << " ";
        stringStack.pop();
    }
    std::cout << std::endl;

    std::cout << "Contents of the stack: ";
    while (!stringStack.empty()) {
        std::cout << stringStack.top() << " ";
        stringStack.pop();
    }
    std::cout << std::endl;

    std::cout << "Contents of the stack: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}