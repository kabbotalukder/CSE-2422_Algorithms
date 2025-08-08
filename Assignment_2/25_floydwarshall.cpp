#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 100;

void floydWarshall(int nodes, int graph[MAX][MAX]) {
    int dist[MAX][MAX];

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes = 4;
    int graph[MAX][MAX];

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;

    floydWarshall(nodes, graph);

    return 0;
}
