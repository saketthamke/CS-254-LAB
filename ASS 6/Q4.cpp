#include <bits/stdc++.h>

using namespace std;

bool dfscycle(vector<int> adj[] , int n , int src , vector<bool>& vis , vector<bool>& dfs) {
    bool ans = false;
    for (int j : adj[src]) {
        if (dfs[j]) {
            return true;
        }
        else if (!vis[j]) {
            vis[j] = true;
            dfs[j] = true;
            ans |= dfscycle(adj , n , j , vis , dfs);
            dfs[j] = false;
            if (ans)
                break;
        }
    }

    return ans;
}

int main() {
        int V , E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int from , to;
            cin >> from >> to;
            adj[from].push_back(to);
        }
        vector<bool> vis(V , false) , dfs(V , false);

        vis[0] = dfs[0] = true;
        bool ans = dfscycle(adj , V , 0 , vis , dfs);

        if (ans) {
            cout << "Cycle is present\n";
        }
        else {
            cout << "Cycle is not present\n";
        }

    return 0;
}