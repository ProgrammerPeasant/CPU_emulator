#include "library.h"

#include <iostream>

template <class T> Stack<T>::Stack() { row = -1; }

template <class T> bool Stack<T>::Empty() {
    if (row == -1) return true;
    else return false;
}

template <class T> bool Stack<T>::Full() {
    if (row == (SIZE - 1)) return true;
    else return false;
}

template <class T> T Stack<T>::pop() {
    T element = arr[row];

    row--;

    return element;
}

template <class T> void Stack<T>::push(T k) {
    if (Full()) {
        std::cerr << "Error: Stack is full. Cannot push more elements.\n";
    }
    else {
        row++;
        arr[row] = k;
    }
};

template <class T> T Stack<T>::top() {
    T top_ele = arr[row];

    return top_ele;
}


