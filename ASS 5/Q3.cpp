#include<bits/stdc++.h>
using namespace std;

bool BFS_with_color_checker(vector<vector<int>>& arr, int v, vector<int>& colortoggle, int s) {
    colortoggle[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < v; i++) {
            if (i != curr) {
                if (!arr[curr][i] && colortoggle[i] == -1) {
                    q.push(i);
                    colortoggle[i] = colortoggle[curr] == 0 ? 1 : 0;
                }
                else if (!arr[curr][i] && colortoggle[i] == colortoggle[curr]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool canBeDivided(vector<vector<int>>& arr, int v) {
    vector<int> colortoggle(v, -1);

    for (int i = 0; i < v; i++) {
        if (colortoggle[i] == -1) {
            if (!BFS_with_color_checker(arr, v, colortoggle, i)) return false;
        }
    }
    return true;
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        if (canBeDivided(arr, n))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}