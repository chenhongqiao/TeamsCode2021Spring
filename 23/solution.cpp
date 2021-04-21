#include <bits/stdc++.h>
using namespace std;
int p[50][105];
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    int ba = c;
    for (int i = 0; i < m - 1; i++)
    {
        int dp[50005];
        for (int j = 0; j < 10005; j++)
        {
            dp[j] = -1000000005;
        }
        dp[ba] = ba;
        for (int j = 0; j < n; j++)
        {
            for (int k = p[i][j]; k <= ba; k++)
            {
                dp[k - p[i][j]] = max(dp[k] + p[i + 1][j] - p[i][j], dp[k - p[i][j]]);
            }
        }
        int lm = 0;
        for (int j = 0; j <= ba; j++)
        {
            lm = max(lm, dp[j]);
        }
        ba = lm;
    }
    cout << ba << endl;
    return 0;
}