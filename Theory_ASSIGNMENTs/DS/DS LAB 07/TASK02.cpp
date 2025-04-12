#include <iostream>
#include <climits>

using namespace std;

void countingSort(int arr[],int size,int pos,bool ascending){
    int freq[10]={0};


    for(int i=0 ; i<size ; i++) freq[(arr[i]/pos)%10]++;

    if(ascending) for(int i=1; i<10; i++) freq[i]+=freq[i-1];
    else for(int i=8; i>=0; i--) freq[i]+=freq[i+1];
    
    int ans[size];
    for(int i=size-1 ; i>-1 ;i--) ans[--freq[(arr[i]/pos)%10]]=arr[i];
    for(int i=0 ; i<size ; i++) arr[i]=ans[i];
}

int max(int a, int b){
    return (a>b) ? a:b;
}

int maxElement(int arr[],int size){
    int m=INT_MIN;
    for(int i=0 ; i<size ; i++) m=max(m,arr[i]);
    return m;
}

void radixSort(int arr[], int size,bool ascending){
    int m=maxElement(arr, size);
    for(int pos=1 ; m/pos>0 ; pos*=10) countingSort(arr,size,pos,ascending);
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
    radixSort(arr,size,true);
    cout<<"Sorted In Ascending Order: ";
    display(arr,size);
    radixSort(arr,size,false);
    cout<<"Sorted In Dscending Order: ";
    display(arr,size);


    delete[] arr;
    return 0;
}
