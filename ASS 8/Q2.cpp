#include<bits/stdc++.h>
using namespace std;

struct DisjointSetUnion{

    vector<int> rank, parent, size;

    DisjointSetUnion(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int FindUltimateParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=FindUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v){

        int Ult_u = FindUltimateParent(u);
        int Ult_v = FindUltimateParent(v);

        if(Ult_u==Ult_v) return;

        if(rank[Ult_u]<rank[Ult_v]){
            parent[Ult_u]=Ult_v;
            return;
        }

        else if(rank[Ult_v]<rank[Ult_u]){
            parent[Ult_v]=Ult_u;
            return;
        }

        parent[Ult_u]=Ult_v;
        rank[Ult_v]++;
        return;
    }

    void UnionBySize(int u, int v){
        int Ult_u = FindUltimateParent(u);
        int Ult_v = FindUltimateParent(v);

        if(Ult_u==Ult_v) return;

        if(size[Ult_u]<size[Ult_v]){
            parent[Ult_u]=Ult_v;
            size[Ult_v]+=size[Ult_u];
            return;
        }else{
            parent[Ult_v]=Ult_u;
            size[Ult_u]+=size[Ult_v];
            return;            
        }        
    }
};

bool validedge(int from, int to, vector<pair<int,int>>& vertexMap, int edgecolor){
    if(vertexMap[from].first==edgecolor) return false;
    if(vertexMap[from].second==edgecolor) return false;
    if(vertexMap[to].first==edgecolor) return false;
    if(vertexMap[to].first==edgecolor) return false;
    return true;
}
int MinSpanningTreeWithAlternatingColors(DisjointSetUnion& ds,int n,vector<vector<int>>& edges,vector<pair<int,int>>& vertexmap,vector<pair<int,int>>& includededges){
	// DisjointSetUnion ds(n);
	auto cmp=[&](vector<int>& a, vector<int>& b){
		if(a[2]<b[2]) return true;
		return false;
	};
	sort(edges.begin(),edges.end(),cmp);
	int sum=0;
	for(auto e:edges){
		int from=e[0];
		int to=e[1];
		int wt=e[2];
        int edgecolor=e[3];

        if(wt==-1) continue;

		if(ds.FindUltimateParent(from) != ds.FindUltimateParent(to) && validedge(from,to,vertexmap,edgecolor) ){
			sum+=wt;
			ds.UnionBySize(from, to);

            if(vertexmap[from].first == -1) vertexmap[from].first=e[3];
            else if(vertexmap[from].second == -1 && e[3]!=vertexmap[from].first) vertexmap[from].second=e[3];
            if(vertexmap[to].first == -1) vertexmap[to].first=e[3];
            else if(vertexmap[to].second == -1 && e[3]!=vertexmap[to].first) vertexmap[to].second=e[3];

            includededges.push_back({from,to});

		}
	}

	return sum;
}

int main(){
    int n,m;
    cin>>n>>m;
    DisjointSetUnion ds(n);
    vector<vector<int>> edges(m,vector<int>(4));
    for(int i=0; i<m; i++){
        for(int j=0; j<4; j++){
            cin>>edges[i][j];
        }
    }

    vector<pair<int,int>> vertexmap(n);
    for(int i=0; i<n; i++){
        vertexmap[i]={-1,-1};
    }
    
    vector<int> adjList[n];
    for(auto e: edges){
        int a=e[0];
        int b=e[1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    set<pair<int,int>> DefiniteEdge;
    for(int i=0; i<n; i++){
        if(adjList[i].size()==1){
            int temp=min(i,adjList[i][0]);
            DefiniteEdge.insert({temp,i+adjList[i][0]-temp});
        }
    }

    int ans=0;
    vector<pair<int,int>> includededges;
    for(auto& e:edges){
        int a=e[0];
        int b=e[1];
        int c=min(a,b);
        int d=a+b-c;
        if(DefiniteEdge.count({c,d})){
            ans+=e[2];
            ds.UnionBySize(a, b);
            e[2]=-1;
            if(vertexmap[c].first == -1) vertexmap[c].first=e[3];
            else if(vertexmap[c].second == -1 && e[3]!=vertexmap[c].first) vertexmap[c].second=e[3];
            if(vertexmap[d].first == -1) vertexmap[d].first=e[3];
            else if(vertexmap[d].second == -1 && e[3]!=vertexmap[d].first) vertexmap[d].second=e[3];
            
            includededges.push_back({a,b});
        }       
    }

    ans+=MinSpanningTreeWithAlternatingColors(ds,n,edges,vertexmap,includededges);
    cout<<"Minimum Spanning Tree with alternating colors = "<<ans<<endl;

    cout<<"Included Edges are:- "<<endl;
    for(int i=0; i<includededges.size(); i++){
        cout<<includededges[i].first<<" "<<includededges[i].second<<endl;
    }
}