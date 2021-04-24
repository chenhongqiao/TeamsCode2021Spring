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

const int maxn = 1e4 + 10;

int n, m, q;
bool og[maxn];
vector <int> edge[maxn];
int d[maxn];

bool cmp(pii a, pii b) {
    if (a.f == b.f) return a.s < b.s;
    return a.f > b.f;
}

void dijkstra() {
    priority_queue <pii, vector <pii>, less <pii> > pq;
    d[1] = 1e9;
    for (int i = 1; i <= n; ++i) {
        if (og[i]) pq.push(mp(d[i], i));
    }
    while (!pq.empty()) {
        int val = pq.top().f, u = pq.top().s;
        pq.pop();
        if (d[u] > val) continue;
        for (int v : edge[u]) {
            if (!og[v] && d[v] < val / 2) {
                d[v] = val / 2;
                pq.push(mp(val / 2, v));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        int a, v;
        scanf("%d%d", &a, &v);
        og[a] = true;
        d[a] = v;
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dijkstra();
    vector <pii> ans;
    for (int i = 2; i <= n; ++i) {
        ans.pb(mp(d[i], i));
    }
    sort(ans.begin(), ans.end(), cmp);
    for (pii i : ans) {
        printf("%d %d\n", i.s, i.f);
    }
}

