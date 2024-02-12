#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int n, m, x[MAXN][MAXN];

int main() {

    int t; 
    cin>>t;

    while(t--){
        cin>>n>>m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>x[i][j];
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (x[i][j] == 0) continue;
                int cnt = 1;
                queue<vector<int> > q;
                q.push({i, j});
                x[i][j] = 0;
                while (!q.empty()) {
                    vector<int> front = q.front();
                    q.pop();
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int nx = dx + front[0];
                            int ny = dy + front[1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < m && x[nx][ny] == 1) {
                                x[nx][ny] = 0;
                                cnt++;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                maxi = max(maxi, cnt);
            }
        }
        cout<<maxi;
    }
    return 0;
}