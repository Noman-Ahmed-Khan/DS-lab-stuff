#include "Queue.h"


    template<typename T>
    Queue_Node<T>::Queue_Node(T value):data(value),next(nullptr) {};



    template<typename T>
    Queue<T>::Queue() : head(nullptr), tail(nullptr) , _size(0) {}
    template<typename T>
    Queue<T>::Queue(const Queue<T>& other) : head(nullptr), tail(nullptr), _size(0) {
        Queue_Node<T>* curr=other.head;
        while (curr){
            enQueue(curr->data);
            curr=curr->next;
        }
    }
    
    template<typename T>
    void Queue<T>::enQueue(T data){
        Queue_Node<T>* newNode=new Queue_Node<T>(data);
        if (!head) {
            head=newNode;
            tail=newNode;
            _size++;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        _size++;
    }
    
    template<typename T>
    T Queue<T>::deQueue(void){
        if(!head) return T();
        Queue_Node<T>* tmp=head;
        head=head->next;
        T val=tmp->data;
        delete tmp;

        _size--;
        if(!head) tail=nullptr;
        return val;
    }

    template<typename T>
    T Queue<T>::front(void){
        if(!head) return T();
        return head->data;
    }

    template<typename T>
    int Queue<T>::size(void){
        return _size;
    }
    
    template<typename T>
    bool Queue<T>::isEmpty(){
        return head==nullptr;
    }
    
    template<typename T>
    void Queue<T>::display(void){
        Queue_Node<T>* curr=head;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    
    template<typename T>
    Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
        if (this==&other) return *this;
        while (!isEmpty()) deQueue();
            _size=other._size;
            Queue_Node<T>* curr=other.head;
            while(curr){
                enQueue(curr->data,curr->priority);
                curr=curr->next;
            }
        return *this;
    }
    
    template<typename T>
    Queue<T>::~Queue() {
        while (!isEmpty()) {
            deQueue();
        }   
    }


