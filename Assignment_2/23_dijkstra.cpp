#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];
int distArr[MAX];

void dijkstra(int nodes, int src) {
    for (int i = 0; i < nodes; i++) {
        distArr[i] = INF;
        visited[i] = false;
    }
    distArr[src] = 0;

    for (int count = 0; count < nodes - 1; count++) {
        int u = -1, minDist = INF;
        for (int i = 0; i < nodes; i++) {
            if (!visited[i] && distArr[i] < minDist) {
                minDist = distArr[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !visited[v] && distArr[u] + graph[u][v] < distArr[v]) {
                distArr[v] = distArr[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << "\t" << distArr[i] << "\n";
    }
}

int main() {
    int nodes = 5;

    memset(graph, 0, sizeof(graph));

    graph[0][1] = 10; graph[1][0] = 10;
    graph[0][4] = 5;  graph[4][0] = 5;
    graph[1][2] = 1;  graph[2][1] = 1;
    graph[1][4] = 2;  graph[4][1] = 2;
    graph[2][3] = 4;  graph[3][2] = 4;
    graph[3][0] = 7;  graph[0][3] = 7;
    graph[3][4] = 6;  graph[4][3] = 6;
    graph[4][2] = 9;  graph[2][4] = 9;

    int source = 0;
    dijkstra(nodes, source);

    return 0;
}
