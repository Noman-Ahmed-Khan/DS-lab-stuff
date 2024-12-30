# include <iostream>
# include <string>
# include <math.h>


using namespace std;


template<typename T>
class Node{
    public:
        Node<T>* next;
        T data;
        Node(T value):data(value),next(nullptr) {};    
};


template<typename T>
class Stack{
    private:
        Node<T>* head;
        int _size;
    public:
        Stack() : head(nullptr), _size(0) {} 
        Stack(const Stack& other) : head(nullptr), _size(0) {
        Node<T>* curr=other.head;
        while (curr){
            push(curr->data);
            curr=curr->next;
        }
    }

        void push(T data){
            Node<T>* newNode=new Node<T>(data);
            newNode->next=head;
            head=newNode;
            _size++;
        }

        T pop(void){
            if(!head) return T();
            _size--;
            Node<T>* tmp=head;
            head=head->next;
            T val=tmp->data;
            delete tmp;
            return val;
        }

        T top(void){
            if(!head) return T();
            return head->data;
        }

        int size(void){
            return _size;
        }

        bool empty(){
            return head==nullptr;
        }
        
        void display(void){
            Node<T>* curr=head;
            while(curr){
                cout<<curr->data<<endl;
                curr=curr->next;
            }
        }
        
        Stack& operator=(const Stack& other) {
            if (this==&other) return *this;  
            
            while (!empty()) pop();
        
            _size=other._size;
            Node<T>* curr=other.head;
            while(curr){
                push(curr->data);
                curr=curr->next;
            }
            return *this;
        }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

};


int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

bool isOperator(char character){
    return (character=='+' || character=='-' || character=='*' || character=='/' || character=='^');
}

bool isAlphabet(char character){
    return ((character>='A' && character<='Z') || (character>='a' && character<='z'));
}

string infixToPostfix(string expression){
    Stack<char> operatorStack;
    string postfix=" ";
    int stringSize=expression.length();
    int index=1;
    for(int i=0 ; i<stringSize ; i++){
        char character=expression[i];
        char characterBefore=(i-1<0) ? ' ' :  expression[i-1];
        if(isspace(character) || isAlphabet(character) || character=='='){
            continue; 
        } else if(character=='.'){
            postfix[index-1]=character;
        } else if((isalnum(character) && isalnum(characterBefore))){
            postfix[index-1]=character;
            postfix+=" ";
            index++;
        }else if(isalnum(character)){
            postfix+=character;
            postfix+=" "; 
            index+=2;
        }else if(character=='('){
            operatorStack.push(character);
        }else if(character==')'){
            while(!operatorStack.empty() && operatorStack.top()!='('){
                postfix+=operatorStack.pop();
                postfix+=" ";
                index+=2;

            }
            operatorStack.pop();
        } else if(isOperator(character)){
            while(!operatorStack.empty() && precedence(character)<=precedence(operatorStack.top())){
                postfix+=operatorStack.pop();
                postfix+=" ";
                index+=2;
            }
            operatorStack.push(character);      
        } 
    }
    while(!operatorStack.empty()){
        postfix+=operatorStack.pop();
        postfix+=" ";
        index+=2;
    }
    return postfix;
}

int read(string expression, int index){ 
    while(expression[++index]!=' ') {};
    return index+1;
}
string getSubstring(string str, int startIndex, int endIndex) {
    if (startIndex<0) startIndex=0;
    if (endIndex>str.length()) endIndex=str.length();    
    if (startIndex>endIndex) return "";

    return str.substr(startIndex, endIndex-startIndex);;
}

float convert(string num){
    float numConverted;
    try{
        numConverted=stof(num);
    } catch(...){
        numConverted=float(stoi(num));
    }

    return numConverted;
}

float solve(float num01,float num02, char operation){
    if(operation=='+') return num01+num02;
    else if(operation=='-') return num01-num02;
    else if(operation=='*') return num01*num02;
    else if(operation=='/') return num01/num02;
    else if(operation=='^') return pow(num01,num02);
}


float evaluatePostfix(string postfix){
    Stack<float> operandStack;
    int leftIndex=1;
    int stringSize=postfix.length();
    while(leftIndex<stringSize){
        int rightIndex=read(postfix,leftIndex);
        string data=getSubstring(postfix,leftIndex,rightIndex);
        if(data=="" && data==" "){
            continue;
        } else if(!isOperator(*data.c_str())){
            operandStack.push(convert(data));
        } else if(!operandStack.empty()){
            float num02=operandStack.pop();
            float num01=operandStack.pop();
            operandStack.push(solve(num01,num02,*data.c_str()));
            // cout<<num01<<" "<<*data.c_str()<<" "<<num02<<" "<<operandStack.top()<<endl;
        }
        leftIndex=rightIndex;
    }
    return operandStack.top();
}


int main(){
    string equation="x=12+13-5*(0.5+0.5)+1";
    string postfix=infixToPostfix(equation);


    Stack<string> expressionStack;
    expressionStack.push(equation);
    expressionStack.push("x="+to_string((int)evaluatePostfix(postfix)));
    
    expressionStack.display();
    return 0;
}