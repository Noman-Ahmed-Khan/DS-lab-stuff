#ifndef QUEUE_H
#define QUEUE_H 

#include<iostream>
using namespace std;
template<typename T>
class Queue_Node{
    public:
        Queue_Node<T>* next;
        T data;
        Queue_Node(T value);
};


template<typename T>
class Queue{
    private:
        Queue_Node<T>* head;
        Queue_Node<T>* tail;
        int _size;
        
    public:
        Queue();
        Queue(const Queue& other);

        void enQueue(T data);
        T deQueue(void);
        
        T front(void);
        int size(void);
        bool isEmpty();
        void display(void);
        Queue<T>& operator=(const Queue<T>& other);
        
        ~Queue();
};

#include "Queue.tpp"

#endif