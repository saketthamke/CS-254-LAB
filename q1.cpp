#include <bits/stdc++.h>

using namespace std;

    int maxPossibleSum(vector<int>& a){
        int max=a[0];
        int maxIndex=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]>max){
                max=a[i]; 
                maxIndex=i;
            }    
        }
        swap(a[maxIndex],a[a.size()-1]);
        max=a[0];
        maxIndex=0;
        for(int i=0; i<a.size()-1; i++){
            if(a[i]>max){
                max=a[i]; 
                maxIndex=i;
            }    
        }
        swap(a[maxIndex],a[a.size()-2]);
        return a[a.size()-1] + a[a.size()-2];
    }

int main(){
    vector<int>a;
    int size;
    cin>>size;
    for(int i=0; i<size; i++){
        int input;
        cin>>input;
        a.push_back(input);
    }
    int ans = maxPossibleSum(a);
    cout<<ans;
}