#include<iostream>
#include "Queue.h"
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
        

        int height(Node<T>* root){
            if(!root) return 0;
            int left_h=height(root->left);
            int right_h=height(root->right);
            return (left_h>right_h)? left_h+1:right_h+1;
        }

        void print_current_level(Node<T>* root,int level){
            if(!root) return;
            if(level==0) cout<<root->key<<" ";
            if(level>0){
                print_current_level(root->left,level-1);
                print_current_level(root->right,level-1);
            }
        }

        void levelOrder_traversal(){
            levelOrder_traversal(root);
        }

        void levelOrder_traversal(Node<T>* root){
            int h=height(root);
            for(int i=0 ; i<h ; i++) {
                print_current_level(root,i);
                cout<<endl;
            }
                
        }

        bool is_full(){
            return is_full(root);
        }
        bool is_full(Node<T>* root){
            if(!root) return true;
            bool left=is_full(root->left);
            bool right=is_full(root->right);

            return ((!root->left && !root->right) || (root->left && root->right)) && left && right;
        }
        bool is_Complete() {
            return is_Complete(root);
        }
        bool is_Complete(Node<T>* root) {
            if (!root) return true;
            Queue<Node<T>*> q;
            q.enQueue(root);
            bool flag=false;
            
            while (!q.isEmpty()) {
                Node<T>* currentNode = q.deQueue();
                
                if(!currentNode){
                    flag=true;
                    continue;
                }
                if(flag) return false;
                if(currentNode->left) q.enQueue(currentNode->left);
                if(currentNode->right) q.enQueue(currentNode->right);
            }
            return true;
        }
        void convert(){
            convert(root);
        }

        void convert(Node<T>* root){
            if(!root) return;
            convert(root->left);
            convert(root->right);

            if(!(!root->left && !root->right || root->left && root->right)){
                if(root->left){
                    delete root->left;
                    root->left=nullptr;
                } else {
                    delete root->right;
                    root->right=nullptr;
                } 
            }
            
        }    
};



int main(){

    Binary_tree<int> tree;
    //0 1 2 3 4 5 6 7
    //1 2 3 4 5 6 7 8
    int arr[] ={1, 2, 3, 4, 5, 6, 7, 8};
    int size=sizeof(arr)/sizeof(arr[0]);
    tree.insert_levelOrder(arr,size);
    
    cout<<"TREE:"<<endl;
    tree.levelOrder_traversal();
    cout<<endl;
    
    if(tree.is_Complete()) cout<<"TREE IS COMPLETE"<<endl;
    else cout<<"TREE IS NOT COMPLETE"<<endl;
    if(tree.is_full()) cout<<"TREE IS FULL"<<endl;
    else cout<<"TREE IS NOT FULL"<<endl;
    
    cout<<endl;
    tree.convert();
    cout<<"TREE AFTER CONVERTING"<<endl;
    tree.levelOrder_traversal();
    
    if(tree.is_Complete()) cout<<"TREE IS COMPLETE"<<endl;
    else cout<<"TREE IS NOT COMPLETE"<<endl;
    if(tree.is_full()) cout<<"TREE IS FULL"<<endl;
    else cout<<"TREE IS NOT FULL"<<endl;
    
    return 0;
}