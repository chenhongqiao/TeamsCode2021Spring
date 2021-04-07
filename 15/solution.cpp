#include <bits/stdc++.h>
using namespace std;
short int g[1005][1005];
short int dx[4] = {1, -1, 0, 0};
short int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
queue<int> ans;
bool v[1005][1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    q.push({0, 0});
    ans.push(0);
    v[0][0] = true;
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int kx = q.front().first + dx[i];
            int ky = q.front().second + dy[i];
            if (kx >= 0 && kx < n && ky >= 0 && ky < n && !v[kx][ky] && g[kx][ky] == 0)
            {
                v[kx][ky] = true;
                if (kx == n - 1 && ky == 0)
                {
                    cout << ans.front() + 1 << endl;
                    exit(0);
                }
                q.push({kx, ky});
                ans.push(ans.front() + 1);
            }
        }
        q.pop();
        ans.pop();
    }
    cout << -1 << endl;
    return 0;
}