
#include <iostream>
using namespace std;


void swap(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}


class Heap{
    private:
        int arr[100];
        int pos;
        bool type;
    public:
        Heap(bool _type):type(_type),pos(-1){};
        Heap(const Heap& obj) : type(obj.type), pos(obj.pos) {
            for (int i=0; i<=pos; i++) this->arr[i]=obj.arr[i];
        }
        void heapify_up(int index){
            if(index<1) return;
            int parent=(index-1)/2;


            if(type && arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                heapify_up(parent);
            } else if(!type && arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                heapify_up(parent);    
            }
        }

        void heapify_down(int index){
            int leftChild=2*index+1;
            int rightChild=2*index+2;
            int minIndex=index;

            if(type){
                if(leftChild<=pos && arr[leftChild]>arr[minIndex]) minIndex=leftChild;
                if(rightChild<=pos && arr[rightChild]>arr[minIndex]) minIndex=rightChild;
            } else{
                if(leftChild<=pos && arr[leftChild]<arr[minIndex]) minIndex=leftChild;
                if(rightChild<=pos && arr[rightChild]<arr[minIndex]) minIndex=rightChild;
            }
            
            if(minIndex!=index){
                swap(arr[minIndex],arr[index]);
                heapify_down(minIndex);
            }
        }

        void changeType(bool type){
            this->type=type;
            for(int i=(pos+2)/2 ; i>=0 ; i--){
                heapify_down(i);
            }
        }
        void insert(int val){
            if(pos+1>=100) return;
            arr[++pos]=val;

            heapify_up(pos);  
        }
        int remove(int index){
            if(pos<0 || index<0 || index>pos) return -1;
            int tmp=arr[index];
            arr[index]=arr[pos--];
            heapify_down(index);
            return tmp;
        }
   
        void printHeap() {
            for (int i=0; i<=pos; ++i) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        bool isEmpty(){
            return pos<0;
        }

};


int main(){

    Heap heap(true);
    heap.insert(35);
    heap.insert(33);
    heap.insert(42);
    heap.insert(10);
    heap.insert(14);
    heap.insert(19);
    heap.insert(27);
    heap.insert(44);
    heap.insert(26);
    heap.insert(31);

    cout<<"Min Heap"<<endl;
    heap.printHeap();
    cout<<endl;
    heap.remove(0);
    cout<<"After deleting the root. Max Heap"<<endl;
    heap.changeType(false);
    heap.printHeap();
    cout<<endl;
    cout<<"Sorted Manner: "<<endl;
    
    Heap tmp=heap;
    while(!tmp.isEmpty()){
        cout<<tmp.remove(0)<<" ";
    }
    
    return 0;
}
