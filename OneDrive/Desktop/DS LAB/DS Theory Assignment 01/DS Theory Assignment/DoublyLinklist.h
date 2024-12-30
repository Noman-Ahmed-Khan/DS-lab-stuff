#ifndef DOUBLY_LINKLIST_H
#define DOUBLY_LINKLIST_H


#include <iostream>
using namespace std;


template<typename T>
class D_Node{
    public:
    T data;
    D_Node<T>* next=nullptr;
    D_Node<T>* prev=nullptr;
    D_Node(T val);
};


template<typename T>
class D_Linklist{
    private:
        D_Node<T>* head;
        D_Node<T>* tail;

    public:
        D_Linklist();
        D_Linklist(T val);
        void add_node_at_tail(T val);
        void add_node_at_head(T val);
        void add_node_at_pos(T val,int index);
        void remove_node_at_tail(void);
        void remove_node_at_head(void);
        void remove_node_at_pos(int index);
        D_Node<T>*& get_head(void);
        D_Node<T>*& get_tail(void);
};


#include "DoublyLinklist.tpp"

#endif