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

const int maxn = 11;

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
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int t;
            scanf("%d", &t);
            req[i].pb(t);
        }
    }
    for (int i = 0; i < (1 << 
}

