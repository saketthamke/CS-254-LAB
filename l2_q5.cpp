#include <bits/stdc++.h>
using namespace std;

vector<int> minimum_elements(vector<int> &v)
{
    int mx1 = INT64_MAX, mx2 = INT64_MAX;
    for (auto it : v)
    {
        if (it < mx1)
        {
            mx2 = mx1;
            mx1 = it;
        }
        else if (it < mx2)
        {
            mx2 = it;
        }
    }
    return {mx1, mx2};
}

int main()
{
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> ans = minimum_elements(v);
        cout << "1st Smallest Element- " << ans[0] << endl;
        cout << "2nd Smallest Element- " << ans[1] << endl;
        cout << endl;
    }
}