#include "Stack.h"

template<typename T>
S_Node<T>::S_Node(T value):data(value),next(nullptr) {}; // Time Complexity: O(1)




template<typename T>
void Stack<T>::insertAtTail(T val){ // Time Complexity: O(1)
    S_Node<T>* newNode=new S_Node<T>(val);
    if(!head){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=tail->next;
    _size++;
}

template<typename T>
Stack<T>::Stack() : head(nullptr), _size(0) {} // Time Complexity: O(1)
template<typename T>
Stack<T>::Stack(const Stack& other) : head(nullptr),tail(nullptr) , _size(0) { // Time Complexity: O(n), where n is the size of the other stack

    S_Node<T>* curr=other.head;
    while (curr){
        insertAtTail(curr->data);
        curr=curr->next;
    }
}

template<typename T>
void Stack<T>::push(T data){ // Time Complexity: O(1)
    S_Node<T>* newNode=new S_Node<T>(data);
    if(!head){
        head=newNode;
        tail=head;
        return;
    }
    newNode->next=head;
    head=newNode;
    _size++;
}

template<typename T>
T Stack<T>::pop(void){ // Time Complexity: O(1)
    if(!head) return T();
    _size--;
    S_Node<T>* tmp=head;
    head=head->next;
    T val=tmp->data;
    delete tmp;
    return val;
}

template<typename T>
T Stack<T>::top(void){ // Time Complexity: O(1)
    if(!head) return T();
    return head->data;
}

template<typename T>
int Stack<T>::size(void){ // Time Complexity: O(1)
    return _size;
}

template<typename T>
bool Stack<T>::isEmpty(){ // Time Complexity: O(1)
    return head==nullptr;
}

template<typename T>
void Stack<T>::display(void){ // Time Complexity: O(n), where n is the size of the stack
    S_Node<T>* curr=head;
    while(curr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) { // Time Complexity: O(n), where n is the size of the other stack
    if (this==&other) return *this;
    while (!isEmpty()) pop();
    _size=other._size;
    S_Node<T>* curr=other.head;
    while(curr){
        insertAtTail(curr->data);
        curr=curr->next;
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack() { // Time Complexity: O(n), where n is the size of the stack
    while (!isEmpty()) {
        pop();
    }   
}