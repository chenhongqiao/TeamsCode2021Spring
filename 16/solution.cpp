#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> df;
bool mp[1005];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int n, m, q;
int ans[1005];
vector<int> g[1005];
void bfs(int f, int fv)
{
    bool vis[1005];
    queue<pair<int, int>> q;
    q.push({f, fv});
    vis[f] = true;
    while (!q.empty())
    {
        auto k = q.front();
        ans[k.first] = max(ans[k.first], k.second);
        for (int i = 0; i < g[k.first].size(); i++)
        {
            if (!vis[g[k.first][i]] && !mp[g[k.first][i]] && k.second / 2 > ans[g[k.first][i]])
            {
                vis[g[k.first][i]] = true;
                q.push({g[k.first][i], k.second / 2});
            }
        }
        q.pop();
    }
}
vector<pair<int, int>> ar;
int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int f, v;
        cin >> f >> v;
        df.push_back({f, v});
        mp[f] = true;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    sort(df.begin(), df.end(), cmp);
    for (int i = 0; i < df.size(); i++)
    {
        bfs(df[i].first, df[i].second);
    }
    for (int i = 1; i <= n; i++)
    {
        ar.push_back({i, ans[i]});
    }
    sort(ar.begin(), ar.end(), cmp1);
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i].first << " " << ar[i].second << endl;
    }
    return 0;
}