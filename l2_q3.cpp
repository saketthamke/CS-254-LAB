#include <bits/stdc++.h>
using namespace std;

void merge(int n, int m, vector<int> &a)
{
    for (int i = m; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void insertionsort(int n, vector<int> &a)
{
    for (int i = 1; i < n; i++)
    {
        merge(i + 1, i, a);
    }
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
            cin >> a[i];

        insertionsort(n, a);

        cout << "The merged array " << tt << " is: \n";
        for (auto it : a)
            cout << it << " ";
        cout << endl;
    }
}