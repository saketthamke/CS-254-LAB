#include <bits/stdc++.h>
using namespace std;
// Function to merge a and b
vector<int> merged_intersection(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
            ans.push_back(a[i]);
        if (a[i] <= b[j])
        {
            i++;
            while (i < a.size() && a[i - 1] == a[i])
                i++;
        }
        else
        {
            j++;
            while (j < b.size() && b[j - 1] == b[j])
                j++;
        }
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

        vector<int> ans = merged_intersection(a, b);
        cout << "The merged a ∩ b array " << tt << " is: \n";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}