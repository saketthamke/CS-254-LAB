#include<bits/stdc++.h>

using namespace std;

//Time Complexity:-O(V+E)
//Space Complexity:-O(V+E)

void dfs(int node, vector<vector<int>> adjList, vector<int>& vis, stack<int>& st){
    vis[node]=1;

    for(auto e: adjList[node]){
        if(!vis[e]) dfs(e,adjList,vis,st);
    }

    st.push(node);
}

void dfs2(int node, vector<vector<int>> Radj, vector<int>& vis, vector<int>& temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto e: Radj[node]){
        if(!vis[e]) dfs2(e,Radj,vis,temp);
    }
}

void Kosaraju(int E, int V ,vector<vector<int>> adjList, vector<vector<int>>& scc){
    stack<int>st;
    vector<int> vis(V,0);

    for(int i=0; i<V; i++){
        if(!vis[i]) dfs(i,adjList,vis,st);
    }

    vector<vector<int>> Radj(V);
    for(int i=0; i<V; i++){
        vis[i]=0;
        for(auto el: adjList[i]){
            Radj[el].push_back(i);
        }
    }

    while(!st.empty()){
        int node=st.top();
        st.pop();
            if(!vis[node]){ 
                vector<int> temp;
                dfs2(node,Radj,vis,temp);
                scc.push_back(temp);
            }
        }
    }



int main(){
    int E,V;
    cin>>V;
    cin>>E;

    vector<vector<int>> adjList(V);
    for(int i=0; i<E; i++){
        int from, to;
        cin>> from >> to ;
        adjList[from].push_back(to);
    }

    vector<vector<int>> scc;
    Kosaraju(E, V, adjList,scc);
    
    for(int i=0; i<scc.size(); i++){
        cout<<"SCC "<<i+1<<" is ";
        for(int j=0; j<scc[i].size(); j++){
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }

}