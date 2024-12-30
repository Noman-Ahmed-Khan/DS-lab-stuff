#include <iostream>
#include <climits>

using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

int partition(int* arr, int low, int high){
    int mid=(low+high)/2;
    swap(arr[mid],arr[high]);
    int pivot=arr[high];
    int index=low-1;
    for (int i=low; i<high; i++) if (arr[i]<=pivot) swap(arr[++index], arr[i]);
    swap(arr[++index], arr[high]);
    return index;
}

void quickSort(int* arr, int low, int high){
    if(low>=high) return;
    int pi=partition(arr, low, high);

    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}

void display(int* arr,int size){
    cout<<endl;
    for (int i=0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int* inputArray(int& size){
    cout<<"Input Array Size:";
    cin>>size;

    int* arr=new int[size];
    for(int i=0 ; i<size ; i++){
        cout<<"Input Element "<<i+1<<" :";
        cin>>arr[size-i-1];
    }

    return arr;
}

int main(){
    
    int* arr;
    int size;
    arr=inputArray(size);
    cout<<endl<<"Unsorted: ";
    display(arr,size);
    quickSort(arr,0,size-1);
    cout<<"Sorted: ";
    display(arr,size);

    delete[] arr;
    return 0;
}