#ifndef BT_H
#define BT_H

#include "data.h"


class BTree_Node {
public:
    vector<table> keys; 
    vector<BTree_Node*> children;
    bool isLeaf;
    int t;  

    BTree_Node(int _t, bool _isLeaf);
    void insertNonFull(table key);
    void splitChild(int i, BTree_Node* y);
    BTree_Node* search(int id);
    void traverse();
    int findKeyIndex(int id);
    void remove(int id);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    table getPredecessor(int idx);
    table getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    bool updateTableById(int id, table newTable);

    friend class BTree;
};


class BTree {
    BTree_Node* root;
    int t;

public:
    BTree(int t);

    void traverse();
    BTree_Node* search(int id);
    void insert(table key);
    void remove(int id);
    bool update(int id, table newTable);
};

#include "BT.tpp"
#endif