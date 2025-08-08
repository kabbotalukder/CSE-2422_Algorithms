#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 100;

int graph[MAX][MAX];
bool inMST[MAX];
int key[MAX];
int parent[MAX];

void primMST(int nodes) {
    for (int i = 0; i < nodes; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < nodes - 1; count++) {
        int u = -1, minKey = INF;
        for (int v = 0; v < nodes; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < nodes; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << totalWeight << endl;
}

int main() {
    int nodes = 5;
    memset(graph, 0, sizeof(graph));
    graph[0][1] = 2; graph[1][0] = 2;
    graph[0][3] = 6; graph[3][0] = 6;
    graph[1][2] = 3; graph[2][1] = 3;
    graph[1][3] = 8; graph[3][1] = 8;
    graph[1][4] = 5; graph[4][1] = 5;
    graph[2][4] = 7; graph[4][2] = 7;
    graph[3][4] = 9; graph[4][3] = 9;
    primMST(nodes);
    return 0;
}
