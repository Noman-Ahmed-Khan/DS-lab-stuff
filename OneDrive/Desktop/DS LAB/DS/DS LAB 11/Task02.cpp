#include <iostream>
using namespace std;

int findPairsWithSum(int arr[], int n, int k) {
    int maxElement = 1000;
    int hashTable[maxElement] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        if (complement >= 0 && hashTable[complement] > 0) {
            count += hashTable[complement];
        }
        hashTable[arr[i]]++;
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << "Number of pairs with sum " << k << ": " << findPairsWithSum(arr, n, k) << endl;
    return 0;
}
