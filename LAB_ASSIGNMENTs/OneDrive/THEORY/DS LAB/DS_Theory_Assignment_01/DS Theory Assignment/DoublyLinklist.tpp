#include <iostream>
#include "DoublyLinklist.h"
using namespace std;

template<typename T>
D_Node<T>::D_Node(T val):data(val){}

template<typename T>
D_Linklist<T>::D_Linklist():head(nullptr),tail(head){}

template<typename T>
D_Linklist<T>::D_Linklist(T val):head(new D_Node<T>(val)),tail(head){}

template<typename T>
void D_Linklist<T>::add_node_at_tail(T val){
    // Time complexity: O(1)
    D_Node<T>* new_node=new D_Node<T>(val);
    if(!head){
        head=new_node;
        tail=head;
        return;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail=tail->next;
    return;
}

template<typename T>
void D_Linklist<T>::add_node_at_head(T val){
    // Time complexity: O(1)
    D_Node<T>* new_node=new D_Node<T>(val);
    if(!head){
        head=new_node;
        tail=head;
        return;
    }
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    return;
}

template<typename T>
void D_Linklist<T>::add_node_at_pos(T val,int index){
    // Time complexity: O(n)
    if(index<0) throw("ERROR INDEX NOT FOUND");
    if(index==0){
        add_node_at_head(val);
        return;
    }
    D_Node<T>* curr=head;
    int i=0;
    while(i++!=index-1){
        if(!curr || !curr->next) throw("ERROR INDEX NOT FOUND");
        curr=curr->next;
    }
    if(curr==tail){
        add_node_at_tail(val);
        return;
    }
    D_Node<T>* new_node=new D_Node<T>(val);
    new_node->next=curr->next;
    curr->next->prev=new_node;
    curr->next=new_node;
    new_node->prev=curr;
    return;
}

template<typename T>
void D_Linklist<T>::remove_node_at_tail(void){
    // Time complexity: O(1)
    if(!head) return;
    if(!head->next){
        D_Node<T>* tmp=head;
        head=nullptr;
        tail=head;
        delete tmp;
        return;
    }
    D_Node<T>* tmp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete tmp;
}

template<typename T>
void D_Linklist<T>::remove_node_at_head(void){
    // Time complexity: O(1)
    if(!head) return;
    if(!head->next){
        D_Node<T>* tmp=head;
        head=nullptr;
        tail=head;
        delete tmp;
        return;
    }
    D_Node<T>* tmp=head;
    head=head->next;
    head->prev=nullptr;
    delete tmp;
}

template<typename T>
void D_Linklist<T>::remove_node_at_pos(int index){
    // Time complexity: O(n)
    if(index<0) throw("ERROR INDEX NOT FOUND");
    if(index==0){
        remove_node_at_head();
        return;
    }
    int i=0;
    D_Node<T>* curr=head;
    while(i++!=index-1){
        if(!curr || !curr->next) throw("ERROR INDEX NOT FOUND");
        curr=curr->next;
    }
    if(curr==tail){
        remove_node_at_tail();
        return;
    }
    D_Node<T>* tmp=curr->next;
    D_Node<T>* nextNode=tmp->next;
    curr->next=nextNode;
    if(nextNode) nextNode->prev=curr;
    delete tmp;
}

template<typename T>
D_Node<T>*& D_Linklist<T>::get_head(void){
    // Time complexity: O(1)
    return head;
}

template<typename T>
D_Node<T>*& D_Linklist<T>::get_tail(void){
    // Time complexity: O(1)
    return tail;
}