*Adjacency Matrix*

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj;
    adj.resize(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

*Input*
5 4
0 1
0 2
1 3
2 4

*Output*
0 1 1 0 0 
1 0 0 1 0 
1 0 0 0 1 
0 1 0 0 0 
0 0 1 0 0 