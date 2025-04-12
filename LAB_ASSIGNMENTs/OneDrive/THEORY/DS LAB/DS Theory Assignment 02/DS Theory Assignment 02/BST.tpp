#include "BST.h"

template<typename T>
BST_Node<T>::BST_Node(T val): key(val),left(nullptr),right(nullptr) {}

BST_Node<table>* BST::findMin(BST_Node<table>* root){
    if(!root->left) return root;
    return findMin(root->left); 
}

BST_Node<table>* BST::insert(BST_Node<table>* root,table val){
    if(!root) return new BST_Node<table>(val);

    if(val.id<root->key.id) root->left=insert(root->left,val);
    else if(val.id>root->key.id) root->right=insert(root->right,val);

    return root;
}

BST_Node<table>* BST::remove(BST_Node<table>* root,int id){
    if(!root) return root;

    if(id<root->key.id) root->left=remove(root->left,id);
    else if(id>root->key.id) root->right=remove(root->right,id);
    
    if(!root->left && !root->right){
        delete root;
        return nullptr;
    } else if(!root->left){
        BST_Node<table>* tmp=root->right;
        delete root;
        return tmp;
    } else if(!root->right){
        BST_Node<table>* tmp=root->left;
        delete root;
        return tmp;
    }      
    
    BST_Node<table>* tmp=findMin(root->right);
    root->key=tmp->key;
    root->right=remove(root->right,tmp->key.id);

    return root;
}

BST_Node<table>* BST::search(BST_Node<table>* root, int id){
    if(!root) return root;

    if(id<root->key.id) root->left=search(root->left,id);
    else if(id>root->key.id) root->right=search(root->right,id);

    return root;
}

bool BST::update(BST_Node<table>* root,table val,int id){
    if(!root) return false;

    if(id<root->key.id) root->left=search(root->left,id);
    else if(id>root->key.id) root->right=search(root->right,id);
    root->key=val;
    return true;
    
}

BST::BST():root(nullptr){}

void BST::insert(table val){
    root=insert(root,val);
}

void BST::remove(int id){
    root=remove(root,id);
}

BST_Node<table>* BST::search(int id){
    return search(root,id);
}

bool BST::update(table val,int id){
    return update(root,val,id);
}
