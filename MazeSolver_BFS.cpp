#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int row;
    int col;
};

void generateMaze(int** maze, int n, int m) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            maze[i][j] = rand() % 2; // Randomly fill 0s and 1s in the maze
        }
    }
}

bool isValid(int** maze, bool** visited, int n, int m, int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m && maze[row][col] == 0 && !visited[row][col]);
}

void BFS(int** maze, bool** visited, Node** parent, int n, int m) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int front = 0, rear = 0;
    Node queue[n * m];
    queue[rear++] = {0, 0};
    visited[0][0] = true;

    while (front < rear) {
        Node current = queue[front++];
        for (int i = 0; i < 8; ++i) {
            int newRow = current.row + directions[i][0];
            int newCol = current.col + directions[i][1];
            if (isValid(maze, visited, n, m, newRow, newCol)) {
                queue[rear++] = {newRow, newCol};
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
            }
        }
    }
}

void printPath(Node** parent, int n, int m) {
    std::cout << "Path from start to end:\n";
    int row = n - 1;
    int col = m - 1;
    while (row != 0 || col != 0) {
        std::cout << "(" << row << ", " << col << ") ";
        Node current = parent[row][col];
        row = current.row;
        col = current.col;
    }
    std::cout << "(0, 0)\n";
}

int main() {
    int n, m;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;
    std::cout << "Enter the number of columns: ";
    std::cin >> m;

    int** maze = new int*[n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
    }

    bool** visited = new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = new bool[m]();
    }

    Node** parent = new Node*[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = new Node[m];
    }

    generateMaze(maze, n, m);

    std::cout << "Maze Generated:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }

    BFS(maze, visited, parent, n, m);
    printPath(parent, n, m);

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] maze[i];
        delete[] visited[i];
        delete[] parent[i];
    }
    delete[] maze;
    delete[] visited;
    delete[] parent;

    return 0;
}
