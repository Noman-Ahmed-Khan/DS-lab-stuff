#include "AVL.h"

template<typename T>
AVL_Node<T>::AVL_Node(T val): key(val),height(1),left(nullptr),right(nullptr) {}

int AVL::getHeight(AVL_Node<table>* root){
    if(!root) return 0;
    return root->height;
}

int AVL::getBalanceFactor(AVL_Node<table>* root){
    if(!root) return 0;
    return getHeight(root->left)-getHeight(root->right);
}

AVL_Node<table>* AVL::rotateLeft(AVL_Node<table>* root){
    if(!root) return root;

    AVL_Node<table>* tmp=root->right;
    AVL_Node<table>* leftChild=tmp->left;

    tmp->left=root;
    root->right=leftChild;

    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    tmp->height=max(getHeight(tmp->left),getHeight(tmp->right))+1;

    return tmp;
}


AVL_Node<table>* AVL::rotateRight(AVL_Node<table>* root){
    if(!root) return root;

    AVL_Node<table>* tmp=root->left;
    AVL_Node<table>* rightChild=tmp->right;

    tmp->right=root;
    root->left=rightChild;

    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    tmp->height=max(getHeight(tmp->left),getHeight(tmp->right))+1;

    return tmp;
}

    AVL_Node<table>* AVL::balanceTree(AVL_Node<table>* root){
        if(!root) return root;

        int bf_root=getBalanceFactor(root);
        int bf_left=getBalanceFactor(root->left);
        int bf_right=getBalanceFactor(root->right);

        if(bf_root>1 && bf_left>=0) return rotateRight(root);    
        if(bf_root>1 && bf_left<0){
            root->left=rotateLeft(root->left);
            return rotateRight(root);
        }    

        if(bf_root>1 && bf_right>=0) return rotateLeft(root);    
        if(bf_root>1 && bf_right<0){
            root->left=rotateRight(root->left);
            return rotateLeft(root);
        }    

        return root;
    }

AVL_Node<table>* AVL::findMin(AVL_Node<table>* root){
    if(!root->left) return root;
    return findMin(root->left); 
}

AVL_Node<table>* AVL::insert(AVL_Node<table>* root,table val){
    if(!root) return new AVL_Node<table>(val);

    if(val.id<root->key.id) root->left=insert(root->left,val);
    else if(val.id>root->key.id) root->right=insert(root->right,val);
    else return root;

    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    return balanceTree(root);
}

AVL_Node<table>* AVL::remove(AVL_Node<table>* root,int id){
    if(!root) return root;

    if(id<root->key.id) root->left=remove(root->left,id);
    else if(id>root->key.id) root->right=remove(root->right,id);
    else {
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        } else if(!root->left){
            AVL_Node<table>* tmp=root->right;
            delete root;
            return tmp;
        } else if(!root->right){
            AVL_Node<table>* tmp=root->left;
            delete root;
            return tmp;
        }      
        
        AVL_Node<table>* tmp=findMin(root->right);
        root->key=tmp->key;
        root->right=remove(root->right,tmp->key.id);
    }

    
            root->height=max(getHeight(root->left),getHeight(root->right))+1;
    return balanceTree(root);
}

AVL_Node<table>* AVL::search(AVL_Node<table>* root, int id){
    if(!root) return root;

    if(id<root->key.id) root->left=search(root->left,id);
    else if(id>root->key.id) root->right=search(root->right,id);

    return root;
}

bool AVL::update(AVL_Node<table>* root,table val,int id){
    if(!root) return false;

    if(id<root->key.id) root->left=search(root->left,id);
    else if(id>root->key.id) root->right=search(root->right,id);
    root->key=val;
    return true;
    
}

AVL::AVL():root(nullptr){}

void AVL::insert(table val){
    root=insert(root,val);
}

void AVL::remove(int id){
    root=remove(root,id);
}

AVL_Node<table>* AVL::search(int id){
    return search(root,id);
}

bool AVL::update(table val,int id){
    return update(root,val,id);
}
