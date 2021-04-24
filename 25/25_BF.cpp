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

const int maxn = 25;

int n, m;
int c[maxn], r[maxn];
vector <int> req[maxn];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &r[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int t;
            scanf("%d", &t);
            req[i].pb(t);
        }
    }
    ll ans = 0;
    bool d[maxn];
    for (int i = 0; i < (1 << m); ++i) {
        ll t = 0;
        memset(d, 0, sizeof(d));
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                t += r[j + 1];
                for (int k : req[j + 1]) {
                    if (!d[k]) {
                        t -= c[k];
                        d[k] = true;
                    }
                }
            }
        }
        ans = max(ans, t);
    }
    printf("%lld", ans);
}

