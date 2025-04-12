#include <iostream>
using namespace std;

int hashFunction(int value, int size) {
    return (value + size) % size; // Handles negative numbers
}

int hasTripletWithZeroSum(int arr[], int n) {
    int hashTable[1000] = {0}; // Fixed-size hash table
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int complement = -(arr[i] + arr[j]);
            int hashIndex = hashFunction(complement, 1000);

            if (hashTable[hashIndex] > 0) {
                return 1;
            }
        }
        int hashIndex = hashFunction(arr[i], 1000);
        hashTable[hashIndex]++;
    }
    return 0;
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Contains triplet with sum zero: " << hasTripletWithZeroSum(arr, n) << endl;
    return 0;
}
