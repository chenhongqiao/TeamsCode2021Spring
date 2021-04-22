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
int g[maxn], gcnt;
vector <int> de[maxn];
int deg[maxn], sz[maxn], cur[maxn];
set <pii> he;
ll ans = 0;

void tarjan(int u) {
    dfn[u] = ++cnt;
    low[u] = dfn[u];
    st.push(u);
    for (int v : edge[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], dfn[v]);
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
        cur[gcnt] = sz[gcnt];
        ans += (ll)sz[gcnt] * (sz[gcnt] - 1) / 2;
        st.pop();
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
                ++deg[g[v]];
            }
        }
    }
    queue <int> q;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : de[u]) {
            ans += (ll)cur[u] * sz[v];
            cur[v] += cur[u];
            --deg[v];
            if (!deg[v]) q.push(v);
        }
    }
    printf("%lld", ans);
}

