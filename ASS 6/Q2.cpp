#include<bits/stdc++.h>

using namespace std;

//Time Complexity:-O(V+E)
//Space Complexity:- O

void LongestPath(vector<vector<pair<int,int>>> adjList, vector<int>& dist, vector<int>& ans){
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto top=pq.top();
        int dis=top.first;
        int node=top.second;
        pq.pop();
        for(auto el: adjList[node]){
            if(dist[el.first]<dist[node]+el.second){
                dist[el.first]=dist[node]+el.second;
                pq.push({dist[el.first],el.first});
            }
        }
    }
}

int main(){

    int E,V;
    cin>>V;
    cin>>E;

    vector<vector<pair<int,int>>> adjList(V);
    for(int i=0; i<E; i++){
        int from, to, weight;
        cin>> from >> to >> weight;
        adjList[from].push_back({to,weight});
    }

    vector<int> dist(V,INT_MIN);
    dist[0]=0;
    vector<int> ans;
    LongestPath(adjList,dist,ans);

    cout<<"The max distance of each node from the source is ";
    for(auto e: dist){
        if(e==INT_MIN) cout<<"Unreachable "; continue;
        cout<<e<<" ";
    }


}