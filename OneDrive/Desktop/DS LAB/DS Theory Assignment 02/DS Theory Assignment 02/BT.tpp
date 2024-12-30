#include "BT.h"

BTree_Node::BTree_Node(int _t, bool _isLeaf): t(_t), isLeaf(_isLeaf) {}

int BTree_Node::findKeyIndex(int id) {
    int idx=0;
    while (idx<keys.size() && keys[idx].id<id) idx++;
    return idx;
}

void BTree_Node::traverse() {
    for (int i=0; i<keys.size(); i++) {
        if (!isLeaf) children[i]->traverse();
        cout<<"ID: "<<keys[i].id<<", Name: "<<keys[i].name<< ", Age: "<<keys[i].age<<endl;
    }
    if (!isLeaf) children[keys.size()]->traverse();
}

BTree_Node* BTree_Node::search(int id) {
    int i=0;
    while (i<keys.size() && id>keys[i].id) i++;

    if (i<keys.size() && keys[i].id==id) return this;
    if (isLeaf) return nullptr;

    return children[i]->search(id);
}


void BTree_Node::insertNonFull(table key) {
    int i=keys.size()-1;

    if (isLeaf) {
        keys.push_back(key);
        while (i>=0 && keys[i].id>key.id) {
            keys[i+1]=keys[i];
            i--;
        }
        keys[i+1]=key;
    } else {
        while (i>=0 && keys[i].id>key.id) i--;

        if (children[i+1]->keys.size()==2*t-1) {
            splitChild(i+1, children[i+1]);
            if (keys[i+1].id<key.id) i++;
        }
        children[i+1]->insertNonFull(key);
    }
}

void BTree_Node::splitChild(int i, BTree_Node* y) {
    BTree_Node* z=new BTree_Node(y->t, y->isLeaf);
    z->keys.assign(y->keys.begin()+t, y->keys.end());
    if (!y->isLeaf) z->children.assign(y->children.begin() + t, y->children.end());
    y->keys.resize(t-1);
    y->children.resize(y->isLeaf? 0:t);

    children.insert(children.begin()+i+1, z);
    keys.insert(keys.begin()+i, y->keys[t-1]);
}

void BTree_Node::remove(int id) {
    int idx=findKeyIndex(id);

    if (idx<keys.size() && keys[idx].id==id) {
        if (isLeaf) removeFromLeaf(idx);
        else removeFromNonLeaf(idx);
    } else {
        if (isLeaf) {
            cout << "The key " << id << " does not exist in the tree.\n";
            return;
        }

        bool flag=(idx==keys.size());
        if (children[idx]->keys.size()<t) fill(idx);

        if (flag && idx>keys.size()) children[idx-1]->remove(id);
        else children[idx]->remove(id);
    }
}

void BTree_Node::removeFromLeaf(int idx) {
    keys.erase(keys.begin() + idx);
}

void BTree_Node::removeFromNonLeaf(int idx) {
    table key=keys[idx];
    if (children[idx]->keys.size()>=t) {
        table pred=getPredecessor(idx);
        keys[idx]=pred;
        children[idx]->remove(pred.id);
    } else if (children[idx+1]->keys.size()>=t) {
        table succ=getSuccessor(idx);
        keys[idx]=succ;
        children[idx+1]->remove(succ.id);
    } else {
        merge(idx);
        children[idx]->remove(key.id);
    }
}

table BTree_Node::getPredecessor(int idx) {
    BTree_Node* cur=children[idx];
    while (!cur->isLeaf) cur=cur->children[cur->keys.size()];
    return cur->keys.back();
}

table BTree_Node::getSuccessor(int idx) {
    BTree_Node* cur=children[idx+1];
    while (!cur->isLeaf) cur=cur->children[0];
    return cur->keys[0];
}

void BTree_Node::fill(int idx) {
    if (idx!=0 && children[idx-1]->keys.size()>=t) borrowFromPrev(idx);
    else if (idx!=keys.size() && children[idx+1]->keys.size()>=t) borrowFromNext(idx);
    else {
        if (idx!=keys.size()) merge(idx);
        else merge(idx-1);
    }
}

void BTree_Node::borrowFromPrev(int idx) {
    BTree_Node* child=children[idx];
    BTree_Node* sibling=children[idx-1];

    child->keys.insert(child->keys.begin(), keys[idx-1]);
    if (!child->isLeaf) child->children.insert(child->children.begin(), sibling->children.back());

    keys[idx-1]=sibling->keys.back();
    sibling->keys.pop_back();
    if (!sibling->isLeaf) sibling->children.pop_back();
}

void BTree_Node::borrowFromNext(int idx) {
    BTree_Node* child=children[idx];
    BTree_Node* sibling=children[idx+1];

    child->keys.push_back(keys[idx]);
    if (!child->isLeaf) child->children.push_back(sibling->children.front());

    keys[idx]=sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());
    if (!sibling->isLeaf) sibling->children.erase(sibling->children.begin());
}

void BTree_Node::merge(int idx) {
    BTree_Node* child=children[idx];
    BTree_Node* sibling=children[idx + 1];

    child->keys.push_back(keys[idx]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
    if (!child->isLeaf) child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());

    keys.erase(keys.begin()+idx);
    children.erase(children.begin()+idx+1);

    delete sibling;
}

    BTree::BTree(int t) : t(t), root(nullptr) {}

    void BTree::traverse() {
        if (root) root->traverse();
    }

    BTree_Node* BTree::search(int id) {
        return root? root->search(id):root;
    }

    void BTree::insert(table key) {
        if (!root) {
            root=new BTree_Node(t, true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size()==2*t-1) {
                BTree_Node* s = new BTree_Node(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i=(s->keys[0].id<key.id) ? 1:0;
                s->children[i]->insertNonFull(key);
                root=s;
            } else root->insertNonFull(key);
        }
    }

    void BTree::remove(int id) {
        if (!root) return;
        root->remove(id);
        if (root->keys.empty()) {
            BTree_Node* tmp=root;
            root=root->isLeaf? nullptr:root->children[0];
            delete tmp;
        }
    }

    bool BTree_Node::updateTableById(int id, table newTable) {
    int i=0;
    while (i<keys.size() && keys[i].id<id) i++;

    if (i<keys.size() && keys[i].id==id) {
        keys[i]=newTable;
        return true;
    }

    if (isLeaf) return false;
    return children[i]->updateTableById(id, newTable);
}


    bool BTree::update(int id, table newTable) {
        if (!root)
            return false;
        return root->updateTableById(id, newTable);
    }
