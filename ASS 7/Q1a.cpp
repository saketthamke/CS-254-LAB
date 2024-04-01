#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    for(int i=0; i<n; i++){
        cin>>values[i];
    }
    int WeightLimit;
    cin>>WeightLimit;

    vector<float> ratio(n);
    vector<vector<float>> group(n);
    for(int i=0; i<n; i++){
        ratio[i]=(float)((float) values[i] / (float) weights[i]);
        vector<float> temp = {ratio[i],(float)weights[i],(float)values[i],(float)i};
        group[i]=temp;
    }

    auto cmp=[&](vector<float>& a, vector<float>& b){
        return a[0]>b[0];
    };
    sort(group.begin(),group.end(),cmp);

    int currweight=0, currprofit=0;
    vector<int> selection;
    for(int i=0; i<n; i++){
        int weight=(int)group[i][1];
        int value=(int)group[i][2];
        int index=(int)group[i][3];

        if(currweight + weight > WeightLimit) continue;
        else{
            currweight+=weight;
            currprofit+=value;
            selection.push_back(index);
        }
    }

    cout<<"Total cost is "<<currprofit<<endl<<"Selected weights are:- ";
    // sort(selection.begin(),selection.end());
    for(int i=0; i<selection.size(); i++){
        cout<<selection[i]<<" ";
    }
}