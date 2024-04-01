#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& jobs){
    int n=jobs.size();

    auto cmp=[&](vector<int>& a, vector<int>& b){
        if(a[2]>b[2]) return true;
    };
    sort(jobs.begin(),jobs.end(),cmp);

    int maxdeadline=INT_MIN;
    for(auto x:jobs){
        maxdeadline=max(maxdeadline,x[1]);
    }

    vector<int> deadlineArr(maxdeadline+1,-1);
    int maxProfit=0;
    vector<int> tasks;

    for(int i=0; i<n; i++){
        int id=jobs[i][0];
        int dead=jobs[i][1];
        int profit=jobs[i][2];

        while(dead>=1 && deadlineArr[dead]!=-1){
            dead--;
        }

        if(dead<1) continue;

        deadlineArr[dead]=id;
        maxProfit+=profit;
    }

    cout<<"The Max profit is "<<maxProfit<<endl;
    cout<<"The order of tasks are ";

    for(int i=1; i<maxdeadline+1; i++){
        if(deadlineArr[i]==-1) continue;
        cout<<deadlineArr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> jobs(n,vector<int>(3));
    for(int i=0; i<n; i++){
        int id,deadline,profit;
        cin>>id>>deadline>>profit;
        jobs[i][0]=id;
        jobs[i][1]=deadline;
        jobs[i][2]=profit;
    }

    solve(jobs);
}