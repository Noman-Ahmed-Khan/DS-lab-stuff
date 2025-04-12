#include "PriorityQueue.h"


template<typename T>
Priority_Node<T>::Priority_Node(T value, int _priority) : data(value), priority(_priority), next(nullptr) {};



template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), _size(0) {}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : head(nullptr), tail(nullptr), _size(0) {
    Priority_Node<T>* curr=other.head;
    while (curr) {
        enQueue(curr->data, curr->priority);
        curr=curr->next;
    }
}

template<typename T>
void Queue<T>::enQueue(T data, int priority) {
    // Time Complexity: O(n), where n is the number of elements in the queue
    Priority_Node<T>* newNode = new Priority_Node<T>(data, priority);
    if (!head || head->priority < priority) {
        newNode->next=head;
        head=newNode;
        if (!tail) tail=newNode;
        _size++;
        return;
    }
    Priority_Node<T>* curr=head;
    while (curr->next && curr->next->priority>=priority) curr=curr->next;
    newNode->next=curr->next;
    curr->next=newNode;
    if (!newNode->next) tail=newNode;
    _size++;
}

template<typename T>
T Queue<T>::deQueue(void) {
    // Time Complexity: O(1)
    if (!head) return T();
    Priority_Node<T>* tmp=head;
    head=head->next;
    T val=tmp->data;
    delete tmp;

    _size--;
    if (_size==0) tail=nullptr;
    return val;
}

template<typename T>
T Queue<T>::front(void) {
    // Time Complexity: O(1)
    if (!head) return T();
    return head->data;
}

template<typename T>
int Queue<T>::size(void) {
    // Time Complexity: O(1)
    return _size;
}

template<typename T>
bool Queue<T>::isEmpty() {
    // Time Complexity: O(1)
    return head==nullptr;
}

template<typename T>
void Queue<T>::display(void) {
    // Time Complexity: O(n), where n is the number of elements in the queue
    Priority_Node<T>* curr=head;
    while (curr) {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    // Time Complexity: O(n), where n is the number of elements in the other queue
    if (this==&other) return *this;
    while (!isEmpty()) deQueue();
    _size=other._size;
    Priority_Node<T>* curr=other.head;
    while (curr) {
        enQueue(curr->data, curr->priority);
        curr=curr->next;
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    // Time Complexity: O(n), where n is the number of elements in the queue
    while (!isEmpty()) {
        deQueue();
    }
}