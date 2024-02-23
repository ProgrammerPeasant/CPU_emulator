#pragma once
#define SIZE 10

template < class T > class Stack {
public:
    Stack();

    T pop();

    void push(T k);

    T top();

    bool Empty();
    bool Full();

private:
    int row;

    T arr[SIZE];

};

