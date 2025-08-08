#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Adjacency matrix using vector
vector<bool> visited;    // Visited array using vector

void dfs(int start, int n) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << " ";

        // Reverse loop to maintain order (optional)
        for (int v = n - 1; v >= 0; v--) {
            if (adj[u][v] == 1 && !visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Resize adjacency matrix and visited vector
    adj.resize(n, vector<int>(n, 0));
    visited.resize(n, false);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1; // Undirected Graph
    }

    int start;
    cin >> start;

    dfs(start, n);
    return 0;
}