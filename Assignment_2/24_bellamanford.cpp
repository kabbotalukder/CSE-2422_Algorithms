#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

const int INF = 1e9;

void bellmanFord(int nodes, int edgesCount, vector<Edge>& edges, int src) {
    vector<int> dist(nodes, INF);
    dist[src] = 0;

    for (int i = 1; i <= nodes - 1; i++) {
        for (int j = 0; j < edgesCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < edgesCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle!\n";
            return;
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int nodes = 5;
    vector<Edge> edges;

    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});

    int edgesCount = edges.size();
    int source = 0;

    bellmanFord(nodes, edgesCount, edges, source);

    return 0;
}
