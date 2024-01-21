#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to merge a and b
vector<int> merged_union(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
            while (i < n && a[i - 1] == a[i])
                i++;
        }
        else if (a[i] > b[j])
        {
            ans.push_back(b[j]);
            j++;
            while (j < m && b[j - 1] == b[j])
                j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++, j++;
            while (i < n && a[i - 1] == a[i])
                i++;
            while (j < m && b[j - 1] == b[j])
                j++;
        }
    }
    while (i < n)
    {
        ans.push_back(a[i]), i++;
        while (i < n && a[i - 1] == a[i])
            i++;
    }
    while (j < m)
    {
        ans.push_back(b[j]), j++;
        while (j < m && b[j - 1] == b[j])
            j++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int n, m;
    for (int tt = 1; tt <= t; tt++)
    {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        vector<int> ans = merged_union(a, b);
        cout << "The merged a U b array " << tt << " is: \n";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}