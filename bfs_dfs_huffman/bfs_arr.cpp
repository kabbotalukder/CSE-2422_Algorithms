#include <iostream>
#include <queue>
using namespace std;

int adj[10][10];     // অ্যাডজাসেন্সি ম্যাট্রিক্স (10 নোড পর্যন্ত)
bool visited[10];    // ভিজিট চেক করার জন্য

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1; // Undirected Graph
    }

    int start;
    cin >> start;

    bfs(start, n);
    return 0;
}
