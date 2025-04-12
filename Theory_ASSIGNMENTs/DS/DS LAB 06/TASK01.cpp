# include <iostream>
using namespace std;

template<typename T>
class Stack{
    private:
        T* stackArray;
        int stackTop;
    public:
        Stack() : stackArray(nullptr), stackTop(-1) {} 
        
        void push(T data){
            stackArray=insertValue(stackArray,stackTop+1,data);
            stackTop++;
        }
        void pop(void){
            if(stackTop<0) return;
            stackArray=removeValue(stackArray,stackTop+1);
            stackTop--;
        }
        T top(void){
            if(stackTop<0) return T();
            return stackArray[stackTop]; 
        }
        int size(void){
            return stackTop+1;
        }
        bool empty(){
            return stackTop<0;
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
            for(int i=0 ; i<size-1 ; i++){
                temp[i]=array[i];
            }
            delete[] array;
            return temp;
        }
        
        
        
        void display(void){
            int curr=stackTop;
            while(curr>-1){
                cout<<stackArray[curr--]<<endl;
            }
        }
        
        Stack& operator=(const Stack& other) {
            if (this == &other) return *this;  
            
            delete[] stackArray;
            stackTop = other.stackTop;
            
            if(other.stackArray!=nullptr){
                stackArray=new T[stackTop+1];
                for(int i=0; i<stackTop+1; i++) {
                    stackArray[i]=other.stackArray[i];
                }
            } else{
                stackArray=nullptr;
            }
            return *this;
        }

        Stack<T> reverseStack(){

        }

        ~Stack() {
            delete[] stackArray;
        }
};

template<typename T>
void insertAtBottom(Stack<T>& st, T value){
    if (st.empty()) {
        st.push(value);
        return;
    }

    T curr=st.top();
    st.pop();
    insertAtBottom(st, value);
    st.push(curr);
}

template<typename T>
void reverse(Stack<T>& st){
    if (st.empty()) return;

    T curr=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,curr);
}



template<typename T>
bool checkPalindrome(Stack<T> stack){
    Stack<T> orignal=stack;
    Stack<T> temp=stack;
    
    reverse(temp);
    while(!orignal.empty()){
        if(orignal.top()!=temp.top()) return false;
        orignal.pop();
        temp.pop();
    };
    return true;
}

int main(){

    Stack<char> st;
    st.push('B');    
    st.push('O');    
    st.push('R');    
    st.push('R');    
    st.push('O');    
    st.push('W');    
    st.push('R');    
    st.push('O');    
    st.push('B');    

    st.display();
    cout<<endl;
    if(checkPalindrome(st)) cout<<"PALINDROME";
    else cout<<"NOT A PALINDROME";
    
    
    return 0;
}