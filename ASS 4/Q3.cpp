#include<bits/stdc++.h>

using namespace std;

//Time Complexity - O(nlogn)
//Space Complexity - O(n)
int KthLargestElement(vector<int>& A, int k){
    if(k>A.size()) return -1;
    priority_queue<int> pq;
    for(int i=0; i<A.size(); i++){
        pq.push(A[i]);
    }
    while(!pq.empty()){
        k--;
        if(k==0) return pq.top();
        pq.pop();
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> A;
    int inp;
    for(int i=0; i<n; i++){
        cin>>inp;
        A.push_back(inp);
    }
    int k;
    cin>>k;

    int ans = KthLargestElement(A, k);

    cout<<ans;
}