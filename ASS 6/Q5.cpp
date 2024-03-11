#include <bits\stdc++.h>

using namespace std;

void bridges(vector<int> adj[] , int n) {
    vector<bool> visited(n , false);
    vector<int> disc(n , -1) , low(n , -1);
    vector<pair<int , int>> ans;
    int timer = 0;

    function<void(int , int)>
        dfs = [&](int node , int p)
        {
            visited[node] = true;
            disc[node] = low[node] = timer++;

            for (int j : adj[node]) {
                if (j == p)
                    continue;

                if (visited[j]) {
                    low[node] = min(low[node] , disc[j]);
                }
                else {
                    dfs(j , node);
                    low[node] = min(low[node] , low[j]);
                    if (low[j] > disc[node])
                        ans.push_back({ node, j });
                }
            }
        };



    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i , -1);
        }
    }

    if (ans.size() == 0) {
        cout << "There are no bridges\n";
    }
    else {
        cout << "The bridges are:\n";
        for (auto p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}

void arpoints(vector<int> adj[] , int n) {
    vector<bool> visited(n , false);
    vector<int> disc(n , -1) , low(n , -1);
    vector<int> ans;
    int timer = 0;

    function<void(int , int)>
        dfs = [&](int node , int p)
        {
            visited[node] = true;
            disc[node] = low[node] = timer++;

            for (int j : adj[node]) {
                if (j == p)
                    continue;

                if (visited[j]) {
                    low[node] = min(low[node] , disc[j]);
                }
                else {
                    dfs(j , node);
                    low[node] = min(low[node] , low[j]);
                    if (low[j] >= disc[node])
                        ans.push_back(node);
                }
            }
        };



    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i , -1);
        }
    }

    if (ans.size() == 0) {
        cout << "There are no articulation points\n";
    }
    else {
        cout << "The articulation points are:\n";
        for (auto p : ans) {
            cout << p << '\n';
        }
    }
}

int main() {
    int V , E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bridges(adj , V);
    arpoints(adj , V);

    return 0;
}