#pragma once
#include <algorithm>
#include <iostream>

template < class T > class Stack {
public:
    int sizeStack;
    Stack() noexcept: capacity(10), topIndex(-1), sizeStack(0) {
        stackArray = new T[capacity];
    }

    // Copy Constructor
    Stack(const Stack& other) : capacity(other.capacity), topIndex(other.topIndex), sizeStack(other.sizeStack) {
        stackArray = new T[capacity];
        for (int i = 0; i <= topIndex; ++i) {
            stackArray[i] = other.stackArray[i];
        }
    }

    // Copy Assignment Operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] stackArray;
            capacity = other.capacity;
            topIndex = other.topIndex;
            sizeStack = other.sizeStack;
            stackArray = new T[capacity];
            for (int i = 0; i <= topIndex; ++i) {
                stackArray[i] = other.stackArray[i];
            }
        }
        return *this;
    }

    // Move Constructor
    Stack(Stack&& other) noexcept : stackArray(other.stackArray), capacity(other.capacity), topIndex(other.topIndex), sizeStack(other.sizeStack) {
        other.stackArray = nullptr;
        other.capacity = 0;
        other.topIndex = -1;
        other.sizeStack = 0;
    }

    // Move Assignment Operator
    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            delete[] stackArray;
            stackArray = other.stackArray;
            capacity = other.capacity;
            topIndex = other.topIndex;
            sizeStack = other.sizeStack;
            other.stackArray = nullptr;
            other.capacity = 0;
            other.topIndex = -1;
            other.sizeStack = 0;
        }
        return *this;
    }

    ~Stack() noexcept{
        delete[] stackArray;
    }

    void push(const T& data) {
        if (topIndex == capacity - 1) {
            T* newStackArray = new T[2 * capacity];
            for (int i = 0; i < capacity; ++i) {
                newStackArray[i] = stackArray[i];
            }
            delete[] stackArray;
            stackArray = newStackArray;
            capacity *= 2;
        }
        sizeStack++;
        stackArray[++topIndex] = data;
    }

    void pop() {
        if (topIndex == -1) {
            throw std::runtime_error("Error: Stack is empty. Cannot pop.\n");
        }
        --sizeStack;
        --topIndex;
        stackArray[topIndex + 1].~T();
    }

    T top() const {
        if (topIndex == -1) {
            throw std::runtime_error("Stack is empty. Cannot get top element.\n");
        }
        return stackArray[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }

    int size() const {
        return sizeStack;
    }

private:
    T* stackArray;
    int capacity;
    int topIndex;
};

