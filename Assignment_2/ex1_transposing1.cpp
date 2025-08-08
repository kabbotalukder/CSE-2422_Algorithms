#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX];
int transpose[MAX][MAX];

void addEdge(int u, int v) {
    adj[u][v] = 1;
}

void transposeGraph(int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            transpose[j][i] = adj[i][j];
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes = 5;

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    printMatrix(adj, nodes);
    transposeGraph(nodes);
    printMatrix(transpose, nodes);
    return 0;
}