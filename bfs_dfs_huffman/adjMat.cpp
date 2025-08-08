*Adjacency List*

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
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
0

*Output*
Adjacency List:
0: 1 2 
1: 0 3 
2: 0 4 
3: 1 
4: 2 