#include <iostream>

using namespace std;

/*You’ve been given an array of numbers representing int datasets. Your task is to datasetentify the int
whose dataset matches the last two digits of your roll number. If your roll number’s last two digits are not present in
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

int interpolation_search(int* &arr,int target,int left,int right){
    if(left>right) return -1;
    
    int mdataset=left+(((right-left)/(arr[right]-arr[left])))*(target-arr[left]);
    if(arr[mdataset]==target) return mdataset;
    else if(arr[mdataset]<target) return interpolation_search(arr, target, mdataset+1, right);
    else return interpolation_search(arr, target, left, mdataset-1);

}

int* input_value(int* array, int& size, int value) {
    int* temp=new int[size+1];
    
    for(int i=0; i<size; ++i) {
        temp[i]=array[i];
    }
    
    temp[size]=value;
    size++;

    delete[] array;
    return temp;
}
bool check_uniformity(int* dataset,int size){
    int diff = dataset[1]-dataset[0];
    for (int i=2; i<size; i++) {
        if (dataset[i]-dataset[i-1]!=diff) return false;
    }
    return true;
}

int main(){
    int size=0;
    int* dataset = new int[size];
    bool stop=false;
    int value;
    char choice;
    while(!stop){
        cout<<"Input Data Element:";
        cin>>value;
        dataset=input_value(dataset,size,value);
        cout<<"Do You Want To Stop (y/n): ";
        cin>>choice;
        if(choice=='y') stop=true;
    }

    system("cls");
    if(!check_uniformity(dataset,size)) throw("Ununiform data");
    sort(dataset,size);
    
    int target;
    cout<<"Input Target value: ";
    cin>>target;
    int index=interpolation_search(dataset,target,0,size-1);
    if(index<0){
        cout<<"Index & Value not found";
    } else {
        cout<<"Target Value At Index: "<<index;
    }

    display(dataset,size);
    cout<<endl;
    
    return 0;
}