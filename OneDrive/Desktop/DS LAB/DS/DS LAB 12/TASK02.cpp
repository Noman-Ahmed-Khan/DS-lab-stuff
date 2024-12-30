#include <iostream>

using namespace std;

int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs(int** grid, int n, int m, int x, int y, bool** visited) {
    visited[x][y] = true;

    for (int i = 0; i < 8; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && !visited[newX][newY]) {
            dfs(grid, n, m, newX, newY, visited);
        }
    }
}

int countIslands(int** grid, int n, int m) {
    bool** visited = new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = new bool[m];
        for (int j = 0; j < m; ++j)
            visited[i][j] = false;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, n, m, i, j, visited);
                count++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        delete[] visited[i];
    delete[] visited;

    return count;
}

int main() {
    int n = 4, m = 2;
    int** grid = new int*[n];
    grid[0] = new int[m]{0, 1};
    grid[1] = new int[m]{1, 0};
    grid[2] = new int[m]{1, 1};
    grid[3] = new int[m]{1, 0};

    cout << countIslands(grid, n, m) << endl;

    for (int i = 0; i < n; ++i)
        delete[] grid[i];
    delete[] grid;

    return 0;
}
