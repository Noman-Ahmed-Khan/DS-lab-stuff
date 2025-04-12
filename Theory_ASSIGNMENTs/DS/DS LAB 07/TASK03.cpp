#include <iostream>
#include <climits>

using namespace std;


void merge(int* arr, int l, int mid, int r,bool ascending){
    int n1=mid-l+1;
    int n2=r-mid;

    int left[n1];
    int right[n2];

    for (int i=0; i<n1; i++) left[i]=arr[l+i];
    for (int j=0; j<n2; j++) right[j]=arr[mid+1+j];


    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(ascending){
            if(left[i]<=right[j]) arr[k++]=left[i++];
            else arr[k++]=right[j++];
        } else {
            if(left[i]>=right[j]) arr[k++]=left[i++];
            else arr[k++]=right[j++];        
        }
    }
    while(i<n1) arr[k++]=left[i++];
    while(j<n2) arr[k++]=right[j++];
}

void mergeSort(int* arr, int left, int right,bool ascending){
    if(left>=right) return;
    int mid=(left+right)/2;

    mergeSort(arr,left,mid,ascending);
    mergeSort(arr,mid+1,right,ascending);

    merge(arr,left,mid,right,ascending);
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
    mergeSort(arr,0,size-1,true);
    cout<<"Sorted In Ascending Order: ";
    display(arr,size);
    mergeSort(arr,0,size-1,false);
    cout<<"Sorted In Dscending Order: ";
    display(arr,size);

    delete[] arr;
    return 0;
}