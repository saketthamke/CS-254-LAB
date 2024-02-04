#include<bits/stdc++.h>

using namespace std;

//Time Complexity - O(log(min(m,n)))
//Space Complexity - O(1)
double MedianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2) return MedianOfTwoSortedArrays(nums2,nums1);
    int low=0;
    int high=n1;
    int left=(n1+n2+1)/2;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2>=1) l2=nums2[mid2-1];
        if (l1<=r2 && l2<=r1){
            if(n%2==0)
            return ((double)(double)max(l1,l2) + (double)min(r1,r2))/2.0;
            else
            return (double)max(l1,l2);
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n;
    vector<int> nums1, nums2;
    int inp;
    for(int i=0; i<n; i++){
        cin>>inp;
        nums1.push_back(inp);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>inp;
        nums2.push_back(inp);
    }

    double ans = MedianOfTwoSortedArrays(nums1, nums2);

    cout<<ans;
}