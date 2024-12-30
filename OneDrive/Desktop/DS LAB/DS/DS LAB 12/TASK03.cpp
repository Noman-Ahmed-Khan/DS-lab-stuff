#include <iostream>

using namespace std;

void createAdjacencyList(int V, int E, int edges[][2]) {
    int** adjList = new int*[V];
    int* sizes = new int[V];

    for (int i = 0; i < V; ++i) {
        adjList[i] = new int[V];
        sizes[i] = 0;
    }

    for (int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];


        adjList[u][sizes[u]++] = v;
        adjList[v][sizes[v]++] = u;
    }

    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int j = 0; j < sizes[i]; ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < V; ++i)
        delete[] adjList[i];
    delete[] adjList;
    delete[] sizes;
}

int main() {
    int V = 5, E = 7;
    int edges[7][2] = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
    createAdjacencyList(V, E, edges);
    return 0;
}
