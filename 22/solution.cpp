#include <bits/stdc++.h>
using namespace std;
int sum[55][55];
int m[55][55][15];
char wf[55][55];
int n, k, l;
int dfs(int r, int c, int s)
{
    if (m[r][c][s] != -1)
    {
        return m[r][c][s];
    }
    m[r][c][s] = 0;
    if (s == 0)
    {
        if (sum[r][c] >= l)
        {
            m[r][c][s] = 1;
        }
    }
    else
    {
        for (int i = r + 1; i < n; i++)
        {
            if (sum[r][c] - sum[i][c] >= l && sum[i][c] >= s)
            {
                m[r][c][s] += (dfs(i, c, s - 1) % 1000000007);
                m[r][c][s] %= 1000000007;
            }
        }
        for (int j = c + 1; j < n; j++)
        {
            if (sum[r][c] - sum[r][j] >= l && sum[r][j] >= s)
            {
                m[r][c][s] += dfs(r, j, s - 1) % 1000000007;
                m[r][c][s] %= 1000000007;
            }
        }
    }
    return m[r][c][s];
}
int main()
{
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> wf[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] + (wf[i][j] == 'S');
        }
    }
    for (int i = 0; i < 55; i++)
    {
        for (int j = 0; j < 55; j++)
        {
            for (int p = 0; p < 15; p++)
            {
                m[i][j][p] = -1;
            }
        }
    }
    cout << dfs(0, 0, k) << endl;
    return 0;
}