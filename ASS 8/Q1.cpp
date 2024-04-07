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

int MaxSpanningTree(int n, vector<vector<int>> &edges, vector<pair<int,int>>& includededges)
{
	DisjointSetUnion ds(n);
	auto cmp=[&](vector<int>& a, vector<int>& b){
		if(a[2]>b[2]) return true;
		return false;
	};
	sort(edges.begin(),edges.end(),cmp);
	int sum=0;
	for(auto e:edges){
		int from=e[0];
		int to=e[1];
		int wt=e[2];

		if(ds.FindUltimateParent(from) != ds.FindUltimateParent(to)){
			sum+=wt;
			ds.UnionBySize(from, to);
            includededges.push_back({from,to});
		}
	}

	return sum;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for(int i=0; i<E; i++){
        for(int j=0; j<3; j++){
            cin>>edges[i][j];
        }
    }

    vector<pair<int,int>> includededges;
    int ans=MaxSpanningTree(V,edges, includededges);
    cout<<"Maximum Spanning Tree sum = "<<ans<<endl;

    cout<<"Included Edges are:- "<<endl;
    for(int i=0; i<includededges.size(); i++){
        cout<<includededges[i].first<<" "<<includededges[i].second<<endl;
    }
}