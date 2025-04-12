#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(void):data(nullptr),capacity(0),currentSize(0){
    resize(2); // Time complexity: O(n), where n is the new capacity
}

template<typename T>
DynamicArray<T>::DynamicArray(int size):data(nullptr),capacity(0),currentSize(0){
    resize(size); // Time complexity: O(n), where n is the new capacity
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
    :capacity(other.capacity),currentSize(other.currentSize),data(new T[other.capacity]){
    for(int i=0;i<currentSize;i++) data[i]=other.data[i]; // Time complexity: O(n), where n is the size of the other DynamicArray
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
    if(this!=&other){        
        delete[] data;       
        capacity=other.capacity;
        currentSize=other.currentSize;
        data=new T[capacity];
        for(int i=0;i<currentSize;i++) data[i]=other.data[i]; // Time complexity: O(n), where n is the size of the other DynamicArray
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::resize(int newCapacity){
    T* tmp=new T[newCapacity];            
    for(int i=0;i<currentSize;i++) tmp[i]=data[i]; // Time complexity: O(n), where n is the current size
    delete[] data;                        
    data=tmp;                             
    capacity=newCapacity;    
    if(currentSize==0 && capacity>1) currentSize=newCapacity; // Time complexity: O(1)
}

template<typename T>
int DynamicArray<T>::size(){
    return currentSize; // Time complexity: O(1)
}

template<typename T>
int DynamicArray<T>::get_capacity(){
    return capacity; // Time complexity: O(1)
}

template<typename T>
void DynamicArray<T>::push_back(T value){
    if(currentSize==capacity) resize(capacity*2); // Time complexity: O(n), where n is the current size
    data[currentSize++]=value;                    // Time complexity: O(1)
}

template<typename T>
void DynamicArray<T>::pop_back(){
    if(currentSize==0) throw out_of_range("DynamicArray IS EMPTY - cannot pop"); // Time complexity: O(1)
    currentSize--;                           // Time complexity: O(1)
}

template<typename T>
T& DynamicArray<T>::operator[](int index){
    if(index>=currentSize) throw out_of_range("INDEX OUT OF RANGE"); // Time complexity: O(1)
    return data[index];                   // Time complexity: O(1)
}

template<typename T>
DynamicArray<T>::~DynamicArray(void){
    delete[] data;                         // Time complexity: O(1)
}