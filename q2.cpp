#include <bits/stdc++.h>

using namespace std;
 
int knapsack(vector<int>& weights, vector<int>& value, int n, int maxWeight, map<pair<int,int>,int>& mp){
    if(n == 0 || maxWeight == 0) return 0;
    if(mp.find({n, maxWeight})!=mp.end()) return mp[{n,maxWeight}];
    if(weights[n-1]>maxWeight) mp[{n,maxWeight}] = knapsack(weights, value, n - 1, maxWeight,mp);
    else mp[{n,maxWeight}] = max(value[n-1] + knapsack(weights, value, n - 1, maxWeight - weights[n-1],mp), knapsack(weights, value, n - 1, maxWeight,mp));
    return mp[{n,maxWeight}];
}
int main(){
    freopen("input2.in","r",stdin);
    freopen("output2.out","w",stdout);
    int n;
    cin >> n;
    
    vector<int> weights, value;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        weights.push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> a;
        value.push_back(a);
    }
    int maxWeight;
    cin >> maxWeight;
    map<pair<int,int>,int> mp;
    int ans = knapsack(weights, value, n, maxWeight, mp);
    cout<<ans;
}
