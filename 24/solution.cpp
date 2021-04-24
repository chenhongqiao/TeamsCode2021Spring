#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
#define pb push_back 
#define mp make_pair
#define f first
#define s second

const int maxn = 1e5 + 10;

int n, m;
vector <int> edge[maxn];
int dfn[maxn], cnt, low[maxn];
stack <int> st;
int g[maxn], gcnt, sz[maxn];
vector <int> de[maxn];
set <pii> he;
ll ans = 0;
bool vis[maxn];

void tarjan(int u) {
    dfn[u] = ++cnt;
    low[u] = dfn[u];
    st.push(u);
    for (int v : edge[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!g[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++gcnt;
        while (st.top() != u) {
            g[st.top()] = gcnt;
            ++sz[gcnt];
            st.pop();
        }
        g[st.top()] = gcnt;
        ++sz[gcnt];
        ans += (ll)sz[gcnt] * (sz[gcnt] - 1) / 2;
        st.pop();
    }
}

void dfs(int u, int val) {
    for (int v : de[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        ans += (ll)val * sz[v];
        dfs(v, val);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].pb(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int u = 1; u <= n; ++u) {
        for (int v : edge[u]) {
            if (g[u] != g[v] && he.find(mp(g[u], g[v])) == he.end()) {
                he.insert(mp(g[u], g[v]));
                de[g[u]].pb(g[v]);
            }
        }
    }
    for (int i = 1; i <= gcnt; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(i, sz[i]);
    }
    printf("%lld", ans);
}

