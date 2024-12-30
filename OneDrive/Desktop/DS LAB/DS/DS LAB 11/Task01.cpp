#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k):key(k),next(nullptr){};
    Node(int k, Node* n):key(k),next(n){};
};

class HashTable {
private:
    static const int size = 10;
    Node* table[size];

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable() {
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, table[index]);
        table[index] = newNode;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp) {
            if (prev)
                prev->next = temp->next;
            else
                table[index] = temp->next;

            delete temp;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << temp->key << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(20);
    ht.insert(34);
    ht.insert(45);
    ht.insert(70);
    ht.insert(56);

    cout << "Hash Table after insertion:\n";
    ht.display();

    cout << "\nSearch 45: " << (ht.search(45) ? "Found" : "Not Found") << endl;
    cout << "Search 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;

    ht.remove(45);
    cout << "\nHash Table after removing 45:\n";
    ht.display();

    return 0;
}
