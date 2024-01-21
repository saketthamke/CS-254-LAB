
#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
        ans.push_back(a[i]), i++;
    while (j < b.size())
        ans.push_back(b[j]), j++;
    return ans;
}

int main()
{
    int t;
    int n, m;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        vector<int> ans = merge(a, b);
        cout << "The merged array " << tt << " is :\n";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}