#include <bits/stdc++.h>
using namespace std;
bool dp[25000000][2]; // 0->next move is other 1->next move is you
int main()
{
    dp[20210424][0] = true;
    for (int i = 20210423; i >= 0; i--)
    {
        dp[i][0] = (dp[i + 1][1] && dp[i + 123][1]);
        dp[i][1] = (dp[i + 1][0] || dp[i + 123][0]);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (dp[s][1])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}