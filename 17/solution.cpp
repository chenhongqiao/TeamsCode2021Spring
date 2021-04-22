#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n, m;
long long ans = 0;
umap<int, umap<int, vector<pair<int, int>>>> g;
umap<int, umap<int, bool>> v;
vector<pair<int, int>> st;
long long bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int cnt = 1;
    while (!q.empty())
    {
        int kx = q.front().first;
        int ky = q.front().second;
        for (int i = 0; i < g[kx][ky].size(); i++)
        {
            int nx = g[kx][ky][i].first;
            int ny = g[kx][ky][i].second;
            if (!v[nx][ny])
            {
                v[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
        q.pop();
    }
    return ((long long)cnt) * (cnt - 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        g[x1][y1].push_back({x2, y2});
        g[x2][y2].push_back({x1, y1});
        st.push_back({x1, y1});
        st.push_back({x2, y2});
    }
    ans = ((long long)n) * n;
    for (int i = 0; i < st.size(); i++)
    {
        if (!v[st[i].first][st[i].second])
        {
            v[st[i].first][st[i].second] = true;
            ans += bfs(st[i].first, st[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}