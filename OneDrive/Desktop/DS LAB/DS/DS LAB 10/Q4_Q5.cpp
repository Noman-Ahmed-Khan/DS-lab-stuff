#include <iostream>
#include <string>
#include <cstring>

using namespace std;


struct Node {
    char character;
    int freq;
    Node* left;
    Node* right;

    Node(char _character, int _freq) : character(_character), freq(_freq), left(nullptr), right(nullptr) {}
    Node(char _character, int _freq,Node* _left,Node* _right) : character(_character), freq(_freq), left(_left), right( _right) {}
};

void swap(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

template<typename T>
class priorityQueue {
private:
    T arr[300];  
    int pos;     

    void heapify_up(int index) {
        if (index<=0) return; 
        int parent=(index-1)/2;

        if (arr[parent]>arr[index]) {
            swap(arr[parent], arr[index]);
            heapify_up(parent);  
        }
    }

    void heapify_down(int index) {
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        int minIndex=index;

        if (leftChild<=pos && arr[leftChild]<arr[minIndex]) minIndex = leftChild;
        if (rightChild<=pos && arr[rightChild]<arr[minIndex]) minIndex = rightChild;
        
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

    void push(T node) {
        if (pos+1>=300) return; 
        
        arr[++pos]=node;  
        heapify_up(pos);    
    }

    T pop(){
        if (pos<0) return T();  
        
        T top=arr[0];  
        arr[0]=arr[pos--];
        heapify_down(0);   

        return top;  
    }

    bool isEmpty(){
        return pos<0;
    }
};

void getCodes(Node* root, string code, string codes[256]) {
    if (!root) return;

    if (!root->left && !root->right && root->character!='\0') codes[(unsigned char)root->character] = code;
    getCodes(root->left, code+"0", codes);
    getCodes(root->right, code+"1", codes);
}

string encodeString(const string& message, string codes[256]) {
    string encoded;
    for (char c:message) encoded += codes[(unsigned char)c];
    return encoded;
}

string decodeString(const string& encoded, Node* root) {
    string decoded;
    Node* current=root;

    for (int i=0 ; i<encoded.length() ; i++) {
         char bit=encoded[i];
        current=(bit=='0')? current->left:current->right;
        if (!current->left && !current->right) {
            decoded+=current->character;
            current=root;
        }
    }
    return decoded;
}

Node* buildHuffmanTree(const string& message) {
    int freq[256]={0};

    for (char c:message) freq[(unsigned char)c]++;
    

    priorityQueue<Node*> queue;
    for (int i=0; i<256; i++) if(freq[i]>0) queue.push(new Node((char)i, freq[i]));
    

    while (queue.getSize()>1) {
        Node* left=queue.pop();
        Node* right=queue.pop();
        queue.push(new Node('\0', left->freq + right->freq, left, right));
    }


    return queue.pop();
}

int main() {
    string message="Noman Ahmed Khan BCS-3F";

    Node* root=buildHuffmanTree(message);

    string codes[256];
    getCodes(root, "", codes);
    string encoded=encodeString(message, codes);
    cout<<"Encoded: "<<encoded<<endl;


    cout<<"Encoded Bits: ";
    cout<<encoded.length()<<endl;

    cout<<"Unencoded Bits: ";
    cout<<message.length()*7<<endl;

    string decoded=decodeString(encoded, root);
    cout<<"Decoded: "<<decoded<<endl;

    return 0;
}
