#include <iostream>

using namespace std;

/*You’ve been given an array of numbers representing int IDs. Your task is to identify the int
whose ID matches the last two digits of your roll number. If your roll number’s last two digits are not present in
the array, insert the missing value in its correct position within the array. You must use binary search to locate the
position of that value within the array.*/



void display(int* &array,int size){
    cout<<endl<<"[ ";
    for(int i=0 ; i<size ; i++){
        cout<<array[i]<<", ";
    }
    cout<<"]"<<endl;
}

void swap(int &num01, int &num02){
    int temp=num01;
    num01=num02;
    num02=temp;
}

void sort(int* &array,int size){
    for(size_t i=0 ; i<size ; i++){
        for(size_t j=i ; j<size ; j++){
            if(array[i]>array[j]){
                swap(array[i],array[j]);
            }
        }
    }
}

int binary_search(int* &arr,int target,int left,int right){
    if(left>right) return (-1*left);
    
    int mid=(left+right)/2;

    if(arr[mid]==target) return mid;
    else if(arr[mid]<target) return binary_search(arr, target, mid+1, right);
    else return binary_search(arr, target, left, mid-1);

}

int* input_value(int* array, int& size,int index, int value) {
    int* temp=new int[size+1];
    
    int j=0;
    for (int i=0; i<size; ++i) {
        if(i!=index){
            temp[i]=array[j]; j++;
        }else{
            temp[i]=value;
        }
    }
    
    temp[size]=value;
    size++;

    delete[] array;
    return temp;
}

int main(){
    // ID: 23K-0647 -> 47
    int size=20;
    int* id = new int[size];
    int random_ids[]={22,45,56,87,90,54,14,54,34,65,76,11,77,42,67,88,53,23,54,23};
    for (int i = 0; i < 20; i++) {
        id[i] = random_ids[i];
    }
    sort(id,size);
    display(id,size);
    cout<<endl;
    
    int index=binary_search(id,47,0,size-1);
    if(index<0){
        id=input_value(id,size,abs(index),47);
        cout<<"Id not found"<<endl<<"Id added to the list at index: "<<abs(index)-1<<endl;
    }else{
        cout<<"Id found in the list at index: "<<index<<endl;
    }
    display(id,size);


    return 0;
}