# include <iostream>
using namespace std;

template<typename T>
class Queue{
    private:
        T* queueArray;
        int _rear;
    public:
        Queue() : queueArray(nullptr), _rear(-1) {} 
        
        void enqueue(T data){
            queueArray=insertValue(queueArray,_rear+1,data);
            _rear++;
        }
        void dequeue(void){
            if(_rear<0) return;
            queueArray=removeValue(queueArray,_rear+1);
            _rear--;
        }
        T rear(void){
            if(_rear<0) return T();
            return queueArray[_rear]; 
        }
        
        T front(void){
            if(_rear<0) return T();
            return queueArray[0]; 
        }
        int size(void){
            return _rear+1;
        }
        bool empty(){
            return _rear<0;
        }
        T* insertValue(T* array,int size,T value){
            T* temp = new T[size+1];
            for(int i=0 ; i<size ; i++){
                temp[i]=array[i];
            }
            temp[size]=value;
            delete[] array;
            return temp;
        }
        

        T* removeValue(T* array,int size){
            T* temp = new T[size-1];
            for(int i=1 ; i<size ; i++){
                temp[i-1]=array[i];
            }
            delete[] array;
            return temp;
        }
        
        
        
        void display(void){
            for(int i=0 ; i<_rear+1 ; i++){
                cout<<queueArray[i]<<" ";
            }
        }
        
        Queue& operator=(const Queue& other) {
            if (this == &other) return *this;  
            
            delete[] queueArray;
            _rear = other._rear;
            
            if(other.queueArray!=nullptr){
                queueArray=new T[_rear+1];
                for(int i=0; i<_rear+1; i++) {
                    queueArray[i]=other.queueArray[i];
                }
            } else{
                queueArray=nullptr;
            }
            return *this;
        }

        ~Queue() {
            delete[] queueArray;
        }
};

class CustomerLane{
    private:
        Queue<int> customerLane;
    public:
        cutomerLane(){};
    
        void checkIn(int ID){
            customerLane.enqueue(ID);
        }
        
		void checkOut(void){
            customerLane.dequeue();
       }
       
       bool anyCustomer(void){
	   		return !customerLane.empty();
	   }
	   
	   int customerBeingProcessed(void){
	   		return customerLane.front();
	   }
       
};

int main(){
   	CustomerLane lane;
	lane.checkIn(10);
	lane.checkIn(8);
	lane.checkIn(6);
	lane.checkIn(1);
	lane.checkIn(4);
	lane.checkIn(7);
	lane.checkIn(13);
	
	while(lane.anyCustomer()){
		char option;
		cout<<"CUSTOMER CHECKOUT (y/n):";
		cin>>option;
		
		if(option=='y'){
			cout<<endl<<"Customer "<<lane.customerBeingProcessed()<<" Checked Out"<<endl;
			lane.checkOut();
				
		} 
	}
	    
	        
	
	
	
	return 0;
}
