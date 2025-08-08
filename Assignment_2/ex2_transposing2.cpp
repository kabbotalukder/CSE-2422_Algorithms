#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX]; 
vector<int> transpose[MAX];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void transposeGraph(int nodes) {
    for (int u = 0; u < nodes; u++) {
        for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }
}

void printGraph(vector<int> graph[], int nodes) {
    for (int i = 0; i < nodes; i++) {
        cout << i << ": ";
        for (int v : graph[i]) {
            cout << v << " ";
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

    printGraph(adj, nodes);
    transposeGraph(nodes);
    printGraph(transpose, nodes);
    return 0;
}
