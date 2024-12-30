#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    


using namespace std;


void swap(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}


template<typename T1,typename T2>
class Pair{
    public:
        T1 first;
        T2 second;
    Pair(): first(T1()),second(T2()){};
    Pair(T1 _first, T2 _second): first(_first),second(_second){};
};

class priorityQueue {
private:
    Pair<string,int> arr[300];  
    int pos;     

    void heapify_up(int index) {
        if (index<=0) return; 
        int parent=(index-1)/2;

        if (arr[parent].second<arr[index].second) {
            swap(arr[parent], arr[index]);
            heapify_up(parent);  
        }
    }

    void heapify_down(int index) {
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        int minIndex=index;

        if (leftChild<=pos && arr[leftChild].second>arr[minIndex].second) minIndex = leftChild;
        if (rightChild<=pos && arr[rightChild].second>arr[minIndex].second) minIndex = rightChild;
        
        if (minIndex != index) {
            swap(arr[minIndex], arr[index]);
            heapify_down(minIndex);  
        }
    }

public:
    priorityQueue() : pos(-1) {} 

    int getSize() {
        return pos+1;
    }

    void push(Pair<string,int> node) {
        if (pos+1>=300) return; 
        
        arr[++pos]=node;  
        heapify_up(pos);    
    }

    Pair<string,int> pop(){
        if (pos<0) return Pair<string,int>("",0);  
        
        Pair<string,int> top=arr[0];  
        arr[0]=arr[pos--];
        heapify_down(0);   

        return top;  
    }

    bool isEmpty(){
        return pos<0;
    }
};

int main(){

    priorityQueue queue;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 10; i++) {
        queue.push(Pair<string, int>("t"+to_string(i), rand()%20));
    }

    while(!queue.isEmpty()){
        Pair<string,int> tmp=queue.pop();
        cout<<tmp.first<<": "<<tmp.second<<endl;
    }


}
