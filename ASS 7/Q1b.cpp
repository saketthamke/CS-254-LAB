#include<bits/stdc++.h>
using namespace std;
// int solve(int index, vector<int>& weights, vector<int>& values, int WeightLimit, vector<vector<int>>& dp){
//     if(index==0){
//         if(weights[index]<=WeightLimit) return values[index];
//         return 0;
//     }

//     if(dp[index][WeightLimit] != -1) return dp[index][WeightLimit];

//     int nottake=0 + solve(index-1,weights,values,WeightLimit,dp);
//     int take=-1e9;
//     if(weights[index]<=WeightLimit) take = values[index] + solve(index-1, weights, values, WeightLimit-weights[index],dp);

//     return dp[index][WeightLimit]=max(take,nottake);
// }
int main(){
    int n;
    cin>>n;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    for(int i=0; i<n; i++){
        cin>>values[i];
    }
    int WeightLimit;
    cin>>WeightLimit;

    vector<vector<int>> dp(n, vector<int>(WeightLimit+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<WeightLimit+1; j++){
            if(i==0){
                if(weights[i]<=j) dp[i][j]=values[i];
                continue;
            }
            int nottake=dp[i-1][j];
            int take=-1e9;
            if(weights[i]<=j) take = values[i] + dp[i-1][j-weights[i]];

            dp[i][j]=max(take,nottake);
        }
    }
    
    cout<<"Total cost is "<<dp[n-1][WeightLimit]<<endl<<"Selected weights are:- ";

    vector<int> selection;
    int x=n-1, y=WeightLimit;
    while(x!=0){
        if(y>=weights[x] && values[x] + dp[x-1][y-weights[x]] > dp[x-1][y]){
            selection.push_back(x);
            y-=weights[x];
        }
        x--;           
    }
    if(dp[0][y] != 0) selection.push_back(0);
    
    sort(selection.begin(),selection.end());
    for(int i=0; i<selection.size(); i++){
        cout<<selection[i]<<" ";
    }
}