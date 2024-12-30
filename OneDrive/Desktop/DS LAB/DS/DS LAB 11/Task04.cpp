#include <iostream>
using namespace std;

void quickSort(char arr[], int low, int high, string order) {
    if (low < high) {
        char pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (order.find(arr[j]) < order.find(pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1, order);
        quickSort(arr, pivotIndex + 1, high, order);
    }
}

void matchNutsAndBolts(char nuts[], char bolts[], int n) {
    string order = "#$%&*@^~";
    quickSort(nuts, 0, n - 1, order);
    quickSort(bolts, 0, n - 1, order);

    cout << "Nuts: ";
    for (int i = 0; i < n; i++)
        cout << nuts[i] << " ";
    cout << "\nBolts: ";
    for (int i = 0; i < n; i++)
        cout << bolts[i] << " ";
    cout << endl;
}

int main() {
    char nuts[] = {'@', '%', '$', '#', '^'};
    char bolts[] = {'%', '@', '#', '$', '^'};
    int n = sizeof(nuts) / sizeof(nuts[0]);

    matchNutsAndBolts(nuts, bolts, n);

    return 0;
}
