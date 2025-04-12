#include <iostream>
using namespace std;


void swap(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

void display(int arr[], int size){
    for (int i=0; i<size; ++i) cout<<arr[i]<<" ";
    
}

void heapify_down(int arr[],int size,int index,bool max) {
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    int tmpIndex=index;

    if(max){
        if (leftChild<size && arr[leftChild]>arr[tmpIndex]) tmpIndex = leftChild;
        if (rightChild<size && arr[rightChild]>arr[tmpIndex]) tmpIndex = rightChild;
    } else {
        if (leftChild<size && arr[leftChild]<arr[tmpIndex]) tmpIndex = leftChild;
        if (rightChild<size && arr[rightChild]<arr[tmpIndex]) tmpIndex = rightChild;    
    }
    
    if (tmpIndex != index) {
        swap(arr[tmpIndex], arr[index]);
        heapify_down(arr,size,tmpIndex,max);  
    }
}

void buildHeap(int arr[],int size,bool max){
    for(int i=(size/2)-1 ; i>=0 ; i--){
        heapify_down(arr,size,i,max);
    }
}

int main(){
    
    int arr[]={7,1,6,3,5,9,10,2,4,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Orignal  : ";
    display(arr,size);
    cout<<endl;
    
    cout<<"Max Heap : ";
    buildHeap(arr,size,true);
    display(arr,size);
    cout<<endl;

    cout<<"Min Heap : ";
    buildHeap(arr,size,false);
    display(arr,size);
    
    return 0;
}
