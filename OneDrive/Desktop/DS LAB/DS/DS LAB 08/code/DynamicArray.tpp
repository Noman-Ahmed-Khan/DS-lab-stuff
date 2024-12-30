#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(void):data(nullptr),capacity(0),currentSize(0){
    resize(2);
}

template<typename T>
DynamicArray<T>::DynamicArray(int size):data(nullptr),capacity(0),currentSize(0){
    resize(size);
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
    :capacity(other.capacity),currentSize(other.currentSize),data(new T[other.capacity]){
    for(int i=0;i<currentSize;i++) data[i]=other.data[i];
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
    if(this!=&other){        
        delete[] data;       
        capacity=other.capacity;
        currentSize=other.currentSize;
        data=new T[capacity];
        for(int i=0;i<currentSize;i++) data[i]=other.data[i];
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::resize(int newCapacity){
    T* tmp=new T[newCapacity];            
    for(int i=0;i<currentSize;i++) tmp[i]=data[i];
    delete[] data;                        
    data=tmp;                             
    capacity=newCapacity;                 
}

template<typename T>
int DynamicArray<T>::size(){
    return currentSize;
}

template<typename T>
int DynamicArray<T>::get_capacity(){
    return capacity;
}

template<typename T>
void DynamicArray<T>::push_back(T value){
    if(currentSize==capacity) resize(capacity*2); 
    data[currentSize++]=value;                    
}

template<typename T>
void DynamicArray<T>::pop_back(){
    if(currentSize==0) throw out_of_range("DynamicArray IS EMPTY - cannot pop"); // Error if empty
    currentSize--;                           
}

template<typename T>
T& DynamicArray<T>::operator[](int index){
    if(index>=currentSize) throw out_of_range("INDEX OUT OF RANGE"); 
    return data[index];                   
}

template<typename T>
DynamicArray<T>::~DynamicArray(void){
    delete[] data;                         
}
