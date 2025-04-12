#ifndef BST_H
#define BST_H

#include "data.h"

template<typename T>
class BST_Node{
public:
    T key;
    BST_Node<table>* left;
    BST_Node<table>* right;
    BST_Node(T val);
};

class BST{
private:
    BST_Node<table>* root;
    BST_Node<table>* findMin(BST_Node<table>* root);

    BST_Node<table>* insert(BST_Node<table>* root,table val);
    BST_Node<table>* remove(BST_Node<table>* root,int id);
    BST_Node<table>* search(BST_Node<table>* root, int id);
    bool update(BST_Node<table>* root,table val,int id);

public:
    BST();

    void insert(table val);
    void remove(int id);
    BST_Node<table>* search(int id);
    bool update(table val,int id);

};


#include "BST.tpp"
#endif