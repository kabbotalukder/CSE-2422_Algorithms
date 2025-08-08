#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[MAX];
int rankArr[MAX];

void makeSet(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankArr[u] < rankArr[v])
            parent[u] = v;
        else if (rankArr[u] > rankArr[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rankArr[u]++;
        }
    }
}

int kruskalMST(vector<Edge>& edges, int nodes) {
    sort(edges.begin(), edges.end(), compare);
    makeSet(nodes);

    int totalWeight = 0;

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            unionSets(e.u, e.v);
            totalWeight += e.weight;
            cout << e.u << " - " << e.v << " : " << e.weight << "\n";
        }
    }

    return totalWeight;
}

int main() {
    int nodes = 6;
    vector<Edge> edges;

    edges.push_back({0, 1, 4});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 2});
    edges.push_back({1, 0, 4});
    edges.push_back({2, 0, 4});
    edges.push_back({2, 1, 2});
    edges.push_back({2, 3, 3});
    edges.push_back({2, 5, 2});
    edges.push_back({2, 4, 4});
    edges.push_back({3, 2, 3});
    edges.push_back({3, 4, 3});
    edges.push_back({4, 2, 4});
    edges.push_back({4, 3, 3});
    edges.push_back({5, 2, 2});
    edges.push_back({5, 4, 3});

    int mstWeight = kruskalMST(edges, nodes);

    cout << mstWeight << endl;

    return 0;
}