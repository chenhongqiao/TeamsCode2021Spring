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
bool vis[maxn];
ll ans = 0;
set <pii> dsc;

void dfs(int u, int p) {
    for (int v : edge[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (dsc.find(mp(p, v)) == dsc.end() && dsc.find(mp(v, p)) == dsc.end()) {
            ++ans;
            dsc.insert(mp(p, v));
        }
        dfs(v, p);
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
        memset(vis, 0, sizeof(vis));
        vis[i] = true;
        dfs(i, i);
    }
    printf("%lld", ans);
}

