#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Queue.h"
using namespace std;

void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

int partition(DynamicArray<int>& arr, int low, int high){
    int pivot=arr[high];
    int index=low-1;
    for (int i=low; i<high; i++) if (arr[i]<=pivot) swap(arr[++index],arr[i]);
    swap(arr[++index], arr[high]);
    return index;
}

void quickSort(DynamicArray<int>& arr, int low, int high){
    if(low>=high) return;
    int pi=partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}
template<typename T>
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    void deleteTree(Node<T>* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    Node<T>* getRoot() {
        return root;
    }
    
    void insert_levelOrder(DynamicArray<T> arr,int size){
        root=insert_levelOrder(arr,size,0);
    }
    Node<T>* insert_levelOrder(DynamicArray<T> arr,int size,int index){
        if(index>=size) return nullptr;
        
        Node<T>* newNode=new Node<T>(arr[index]);

        newNode->left=insert_levelOrder(arr,size,2*index+1);
        newNode->right=insert_levelOrder(arr,size,2*index+2);
        return newNode;
    }


    void addNode(T key) {
        addNode(new Node<T>(key), root);
    }

    void addNode(Node<T>* newNode, Node<T>*& root) {
        if (!root) {
            root = newNode;
            return;
        }
        if (newNode->key == root->key) return;

        if (newNode->key < root->key) addNode(newNode, root->left);
        else addNode(newNode, root->right);
    }

    void print_current_level(Node<T>* root, int level) {
        if (!root) return;
        if (level == 0) cout << root->key << " ";
        else if (level > 0) {
            print_current_level(root->left, level - 1);
            print_current_level(root->right, level - 1);
        }
    }

    void display_levelorder() {
        display_levelorder(root);
    }

    void display_levelorder(Node<T>* root) {
        int h = height(root);
        for (int i = 0; i <= h; i++) {
            print_current_level(root, i);
            cout << endl;
        }
    }

    int max(int i, int j, int k = 0) {
        int tmp = (j > k) ? j : k;
        return (i > tmp) ? i : tmp;
    }

    int height(Node<T>* root) {
        if (!root) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }

    DynamicArray<int> read_levelOrder() {
        return read_levelOrder(root);
    }

    DynamicArray<int> read_levelOrder(Node<int>* root) {
        if (!root) return DynamicArray<int>();

        Queue<Node<int>*> q;
        q.enQueue(root);

        DynamicArray<int> nodes;
        while (!q.isEmpty()) {
            Node<int>* tmp = q.deQueue();
            if(tmp) nodes.push_back(tmp->key);
            if (tmp->left) q.enQueue(tmp->left);
            if (tmp->right) q.enQueue(tmp->right);
        }
    cout<<endl;
        return nodes;
    }

};

    DynamicArray<int> joinTrees(DynamicArray<int>& arr1,DynamicArray<int>& arr2) {
        DynamicArray<int> joinedNodes;
        for (int i = 0; i < arr1.size(); ++i) {
            joinedNodes.push_back(arr1[i]);
        }
        for (int i = 0; i < arr2.size(); ++i) {
            joinedNodes.push_back(arr2[i]);
        }
        quickSort(joinedNodes,0,joinedNodes.size()-1);
        return joinedNodes;
    }

int main() {
    BinarySearchTree<int> BST01;
    BST01.addNode(5);
    BST01.addNode(3);
    BST01.addNode(6);
    BST01.addNode(2);
    BST01.addNode(4);

    BinarySearchTree<int> BST02;
    BST02.addNode(2);
    BST02.addNode(1);
    BST02.addNode(3);
    BST02.addNode(7);
    BST02.addNode(6);

    DynamicArray<int> firstTreeNodes=BST01.read_levelOrder();
    DynamicArray<int> secondTreeNodes=BST02.read_levelOrder();
    DynamicArray<int> joinedTreeNodes = joinTrees(firstTreeNodes, secondTreeNodes);

    cout<<"FIRST TREE: "<<endl;
    BST01.display_levelorder();
    cout<<"SECOND TREE: "<<endl;
    BST02.display_levelorder();
    
    BinarySearchTree<int> joinedBST;
    joinedBST.insert_levelOrder(joinedTreeNodes,joinedTreeNodes.size());
    
    cout<<"JOINED TREE: "<<endl;
    joinedBST.display_levelorder();
    return 0;
}
