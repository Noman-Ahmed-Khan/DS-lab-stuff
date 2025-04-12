#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H 

#include<iostream>

template<typename T>
class Priority_Node{
    public:
        Priority_Node<T>* next;
        int priority;
        T data;
        Priority_Node(T value,int _priority);
};


template<typename T>
class Queue{
    private:
        Priority_Node<T>* head;
        Priority_Node<T>* tail;
        int _size;
        
    public:
        Queue();
        Queue(const Queue& other);

        void enQueue(T data,int priority);
        T deQueue(void);
        
        T front(void);
        int size(void);
        bool isEmpty();
        void display(void);
        Queue<T>& operator=(const Queue<T>& other);
        
        ~Queue();
};

#include "PriorityQueue.tpp"

#endif