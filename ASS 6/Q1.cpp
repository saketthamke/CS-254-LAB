#include<bits/stdc++.h>

using namespace std;

//Time Complexity:- O(V+E)
//Space Complexity:- O(V+E)

void TopoSort(vector<int> indegree, vector<vector<int>> adjList, vector<int>& ans){

    queue<int> q;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]==0) q.push(i);
    }


    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto el: adjList[top]){
            indegree[el]--;
            if(indegree[el]==0) q.push(el);
        }
    }
}

int main(){

    int V,E;
    cin>>V;
    cin>>E;

    vector<vector<int>> adjList(V);
    vector<int> indegree(V,0);
    for(int i=0; i<E; i++){
        int from, to;
        cin>> from;
        cin>>to;
        adjList[from].push_back(to);
        indegree[to]++;
    }

    vector<int> ans;
    TopoSort(indegree, adjList, ans);

    cout<<"The topological sort of the given graph is ";
    for(auto el:ans){
        cout<<el<<" ";
    }

    return 0;
}
