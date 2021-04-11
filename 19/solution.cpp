#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n, m;
umap<string, vector<pair<string, int>>> g;
umap<string, int> dp;
umap<string, bool> v;
void dfs(string u, int ac)
{
    dp[u] = ac;
    for (int i = 0; i < g[u].size(); i++)
    {
        if (!v[g[u][i].first])
        {
            v[g[u][i].first] = true;
            dfs(g[u][i].first, ac + g[u][i].second);
        }
    }
}
int main()
{
    cin >> n >> m;
    string rt;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int x;
        cin >> a >> b >> x;
        if (i == 0)
        {
            rt = a;
        }
        g[a].push_back({b, x});
        g[b].push_back({a, -x});
    }
    v[rt] = true;
    dp[rt] = 0;
    dfs(rt, 0);
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a] << endl;
    }
    return 0;
}