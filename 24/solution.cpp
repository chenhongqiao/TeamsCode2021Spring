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

void tarjan(int u) {
    dfn[u] = ++cnt;
    low[u] = dfn[u];
    st.push(u);
    for (int v : edge[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low

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
}

