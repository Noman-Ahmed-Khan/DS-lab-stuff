#ifndef AVL_H
#define AVL_H
#include "data.h"

template<typename T>
class AVL_Node{
public:
    T key;
    int height;
    AVL_Node<table>* left;
    AVL_Node<table>* right;
    AVL_Node(T val);
};

class AVL{
private:
    AVL_Node<table>* root;
    AVL_Node<table>* findMin(AVL_Node<table>* root);
    
    int getHeight(AVL_Node<table>* root);
    int getBalanceFactor(AVL_Node<table>* root);
    AVL_Node<table>* rotateLeft(AVL_Node<table>* root);
    AVL_Node<table>* rotateRight(AVL_Node<table>* root);
    AVL_Node<table>* balanceTree(AVL_Node<table>* root);
    
    AVL_Node<table>* insert(AVL_Node<table>* root,table val);
    AVL_Node<table>* remove(AVL_Node<table>* root,int id);
    AVL_Node<table>* search(AVL_Node<table>* root, int id);
    bool update(AVL_Node<table>* root,table val,int id);

public:
    AVL();

    void insert(table val);
    void remove(int id);
    AVL_Node<table>* search(int id);
    bool update(table val,int id);

};


#include "AVL.tpp"
#endif