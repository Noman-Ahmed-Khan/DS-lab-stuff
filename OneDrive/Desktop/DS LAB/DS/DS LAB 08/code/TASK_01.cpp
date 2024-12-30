#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:        
        T key;
        Node<T>* left;
        Node<T>* right;
        Node(T val):key(val),left(nullptr),right(nullptr){};
};

template<typename T>
class Binary_tree{
    private:
        Node<T>* root;
    public:
        Binary_tree():root(nullptr){}
        /*
            There are multiple ways to input in Binary tree,
            like levelOrder Preorder, like in BST. Since it is 
            not mention I will do levelOrder insertion;
        */
        void insert_levelOrder(T arr[],int size){
            root=insert_levelOrder(arr,size,0);
        }
        
        Node<T>* insert_levelOrder(T arr[],int size,int index){
            if(index>=size) return nullptr;
            
            Node<T>* newNode=new Node<T>(arr[index]);

            newNode->left=insert_levelOrder(arr,size,2*index+1);
            newNode->right=insert_levelOrder(arr,size,2*index+2);
            return newNode;
        }

        void preOrder_traversal(){
            preOrder_traversal(root);
        }
        
        void preOrder_traversal(Node<T>* root){
            if(!root) return;

            cout<<root->key<<" ";
            preOrder_traversal(root->left);
            preOrder_traversal(root->right);
        }
        
        void print_current_level(Node<T>* root,int level){
            if(!root) return;
            if(level==0) cout<<root->key<<" ";
            else if(level>0){
                print_current_level(root->left,level-1);
                print_current_level(root->right,level-1);
            }
        }
       int max(int i,int j,int k=0){
            int tmp=(j>k)? j:k;
            return (i>tmp)? i:tmp; 
       }       

        int height(Node<T>* root){
            if (!root) return -1;
                return max(height(root->left),height(root->right))+1;
            
        }
        
        void display_levelorder(){
            display_levelorder(root);
        }
        void display_levelorder(Node<T>* root){
            int h= height(root);
            for(int i=0 ; i<=h ; i++){
                print_current_level(root,i);
                cout<<endl;
            }
        }
};


int main(){

    Binary_tree<int> tree;
    int arr[] ={1, 2, 3, 4, 5};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    tree.insert_levelOrder(arr,size);
    // tree.preOrder_traversal();
    tree.display_levelorder();
    return 0;
}