#include <bits/stdc++.h>

using namespace std;

//Time Complexity - O(n^3)
//Space Complexity - O(n^2)

vector<vector<int>> add_matrix(vector<vector<int>> a, vector<vector<int>> b, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] += b[i][j];
        }
    }
    return a;
}

vector<vector<int>> matrix_multiply(vector<vector<int>> &A, vector<vector<int>> &B, int N)
{
    vector<vector<int>> res(N, vector<int>(N, 0));
    if (N == 1)
    {
        res[0][0] = A[0][0] * B[0][0];
        return res;
    }
    int mid = N / 2;

    vector<vector<int>> a00(mid, vector<int>(mid, 0));
    vector<vector<int>> a01(mid, vector<int>(mid, 0));
    vector<vector<int>> a10(mid, vector<int>(mid, 0));
    vector<vector<int>> a11(mid, vector<int>(mid, 0));
    vector<vector<int>> b00(mid, vector<int>(mid, 0));
    vector<vector<int>> b01(mid, vector<int>(mid, 0));
    vector<vector<int>> b10(mid, vector<int>(mid, 0));
    vector<vector<int>> b11(mid, vector<int>(mid, 0));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            a00[i][j] = A[i][j];
            a01[i][j] = A[i][j + mid];
            a10[i][j] = A[mid + i][j];
            a11[i][j] = A[i + mid][j + mid];
            b00[i][j] = B[i][j];
            b01[i][j] = B[i][j + mid];
            b10[i][j] = B[mid + i][j];
            b11[i][j] = B[i + mid][j + mid];
        }
    }
    vector<vector<int>> M1 = add_matrix(matrix_multiply(a00, b00, mid), matrix_multiply(a01, b10, mid), mid);
    vector<vector<int>> M2 = add_matrix(matrix_multiply(a00, b01, mid), matrix_multiply(a01, b11, mid), mid);
    vector<vector<int>> M3 = add_matrix(matrix_multiply(a10, b00, mid), matrix_multiply(a11, b10, mid), mid);
    vector<vector<int>> M4 = add_matrix(matrix_multiply(a10, b01, mid), matrix_multiply(a11, b11, mid), mid);

    for (int i = 0; i < mid; i++)
    {
        for (auto j = 0; j < mid; j++)
        {
            res[i][j] = M1[i][j];
            res[i][j + mid] = M2[i][j];
            res[mid + i][j] = M3[i][j];
            res[i + mid][j + mid] = M4[i][j];
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n, m;
        cin >> m >> n;
        int N = ceil(log2(max(m, n)));
        N = 1 << N;

        vector<vector<int>> A(N, vector<int>(N, 0));
        vector<vector<int>> B(N, vector<int>(N, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> B[i][j];

        vector<vector<int>> ans = matrix_multiply(A, B, N);

        cout << "The answer matrix " << tt << " is ->\n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}