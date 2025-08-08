#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
bool visited[MAX];

void DFS(int start) {
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";

            for (int i = adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 5;

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    DFS(0);

    return 0;
}
