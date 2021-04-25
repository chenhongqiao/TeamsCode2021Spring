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

int n;
pii seg[maxn];

bool cmp(pii a, pii b) {
    if (a.s == b.s) return a.f < b.f;
    else return a.s < b.s;
}

int main() {
    freopen("cases/6.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &seg[i].f, &seg[i].s);
    }
    sort(seg, seg + n, cmp);
    multiset <int> ends;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = ends.lower_bound(seg[i].f);
        if (it != ends.begin()) {
            --it;
            ends.erase(it);
        }
        else ++ans;
        ends.insert(seg[i].s);
    }
    printf("%d", ans);
}

