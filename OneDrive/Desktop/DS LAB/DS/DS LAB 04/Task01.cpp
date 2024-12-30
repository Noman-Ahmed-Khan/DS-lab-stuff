#include <iostream>

using namespace std;



void swap(int &num01, int &num02){
    int temp=num01;
    num01=num02;
    num02=temp;
}

template<size_t size>
void display(int (&array)[size]){
    cout<<endl<<"[ ";
    for(int num : array){
        cout<<num<<", ";
    }
    cout<<"]"<<endl;
}

template<size_t size>
void bubble_sort(int (&array)[size]){
    for(size_t i=0 ; i<size ; i++){
        for(size_t j=1 ; j<size ; j++){
            if(array[j-1]<array[j]){
                swap(array[j-1],array[j]);
            }
        }
    }
}



int main(){
    
    int array[10]= {5,1,3,6,2,9,7,4,8,10};

    display(array);
    bubble_sort(array);
    display(array);


    return 0;
}