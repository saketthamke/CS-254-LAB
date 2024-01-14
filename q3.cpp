#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int fun(int i, int mask, int n, vector<vector<int>>& dp,vector<vector<int>>& graph)
{
	
	if (mask == ((1 << i) | 3))
		return graph[1][i];
	
	if (dp[i][mask] != 0)
		return dp[i][mask];

	int res = MAX;
	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1) res = min(res, fun(j, mask & (~(1 << i)), n, dp, graph) + graph[j][i]);
	return dp[i][mask] = res;
}

int main()
{
    
    freopen("input_3.in","r",stdin);
    freopen("output_3.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(1 << (n + 1),0));
    vector<vector<int>> graph(n+1,vector<int>(n + 1,0));

	int ans = MAX;
    for(int i = 0; i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cin>>graph[i][j];
        }
    }
	for (int i = 1; i <= n; i++) 
        ans = min(ans, fun(i, (1 << (n + 1)) - 1, n, dp, graph) + graph[i][1]);

	cout<<ans;

	return 0;
}

