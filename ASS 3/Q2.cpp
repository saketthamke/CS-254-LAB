#include <bits/stdc++.h>

using namespace std;

//Time Complexity - O(nlogn)
//Space Complexity - O(1);

int solve(int a[],int start, int end){
    int mid=start + (end-start)/2;
    if(start==mid ) return a[mid];
    if(end==mid+1) return a[mid+1];
    int maxileft=INT_MIN;
    int maxiright=INT_MIN;
    int sum=0;
    for(int i=mid;i<=end;i++){
        sum+=a[i];
        if(sum>maxiright) maxiright=sum;
    }
    sum=0;
    for(int i=mid;i>=start;i--){
        sum+=a[i];
        if(sum>maxileft) maxileft=sum;
    }
    return max({
        solve(a,start,mid), 
        solve(a,mid+1,end),
        maxileft+maxiright-a[mid]
    });
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = solve(a,0,n-1);
    cout<<ans;
    return 0;
}
