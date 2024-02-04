# include<bits/stdc++.h>

using namespace std;

//Time Complexity - O(n^2)
//Space Complexity - O(1)
// int BruteInversePair(vector<int>&A, int n){
//     int count=0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(A[j]<A[i])
//             count++;
//         }
//     }

//     return count;
// }


//Time Complexity - O(logn)
//Space Complexity - O(n)
int merge(vector<int>& A, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int ans=0;

    while(left<=mid && right<=high){
        if(A[left]<A[right]){
            temp.push_back(A[left]);
            left++;
        }
        else{
            ans+=mid-left+1;
            temp.push_back(A[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(A[left]);
        left++;        
    }

    while (right<=high)
    {
        temp.push_back(A[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        A[i]=temp[i-low];
    }
    return ans;
}

int OptimizeInversePair(vector<int>& A, int low, int high){
        if(low>= high) return 0;
        int mid=(low+high)/2;
        int ans=0;
        ans += OptimizeInversePair(A, low, mid);
        ans += OptimizeInversePair(A, mid+1, high);
        ans += merge(A,low,mid,high);
        return ans;
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
    // int ans = BruteInversePair(A, n);
    int ans=0;
    ans = OptimizeInversePair(A,0,n-1);
    cout<<ans;
}