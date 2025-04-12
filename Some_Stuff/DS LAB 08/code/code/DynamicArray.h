#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class DynamicArray{
private:
    T* data;                 
    int capacity;            
    int currentSize;         

public:
    DynamicArray(void);                  
    DynamicArray(int size);              
    DynamicArray(const DynamicArray& other); 
    DynamicArray& operator=(const DynamicArray& other); 

    void resize(int newCapacity);        
    int size();                          
    int get_capacity();                  
    void push_back(T value);             
    void pop_back();                     
    T& operator[](int index);            
    ~DynamicArray(void);                 
};

#include "DynamicArray.tpp"

#endif
