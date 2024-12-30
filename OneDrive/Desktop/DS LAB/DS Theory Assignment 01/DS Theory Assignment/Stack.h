#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<typename T>
class S_Node{
    public:
        S_Node<T>* next;
        T data;
        S_Node(T value);
};

template<typename T>
class Stack{
    private:
        S_Node<T>* head;
        S_Node<T>* tail;
        int _size;
        void insertAtTail(T val);
    public:
        Stack();
        Stack(const Stack& other);
        void push(T data);
        
        T pop(void);
        T top(void);

        int size(void);
        
        bool isEmpty();
        
        void display(void);
        
        Stack<T>& operator=(const Stack<T>& other);
        
        ~Stack();
};

#include "Stack.tpp"
#endif