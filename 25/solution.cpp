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
typedef pair<int, int> pii;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

<<<<<<< HEAD
const int maxn = 5e6 + 10, inf = 1e9;
=======
const int maxn = 5e4 + 10, inf = 1e9 + 10;
>>>>>>> e93fce775077be747f2fd5ed0fbd38f65aa2772f

int n, m; //number of tasks, number of rewards
int c[maxn], r[maxn];

//first m nodes are rewards, next n nodes are tasks, n + m + 1 is supersource, n + m + 2 is supersink
int s, t;

struct edge
{
    int to, nxt, cp;
<<<<<<< HEAD
} p[5000020];
int ohead[maxn], head[maxn], ecnt = 2;
=======
}p[5000020];
int ohead[maxn << 1], head[maxn << 1], ecnt = 2;
>>>>>>> e93fce775077be747f2fd5ed0fbd38f65aa2772f

void addedge(int u, int v, int c)
{
    p[ecnt].nxt = ohead[u];
    p[ecnt].to = v;
    p[ecnt].cp = c;
    ohead[u] = ecnt++;
    p[ecnt].nxt = ohead[v];
    p[ecnt].to = u;
    p[ecnt].cp = 0;
    ohead[v] = ecnt++;
}

int dep[maxn];

bool set_dep()
{
    memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        head[u] = ohead[u];
        if (u == t)
            return true;
        for (int i = head[u]; i; i = p[i].nxt)
        {
            int v = p[i].to;
            if (dep[v] || !p[i].cp)
                continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
    return false;
}

ll aug(int u, ll f)
{
    if (u == t)
        return f;
    ll ans = 0;
    for (int i = head[u]; i; i = p[i].nxt)
    {
        int v = p[i].to;
        if (dep[v] == dep[u] + 1)
        {
            ll nf = aug(v, min((ll)p[i].cp, f));
            ans += nf;
            p[i].cp -= nf;
            p[i ^ 1].cp += nf;
            f -= nf;
        }
        if (f)
            head[u] = i;
        else
            break;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    s = n + m + 1, t = n + m + 2;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &c[i]);
        addedge(m + i, t, c[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &r[i]);
        ans += r[i];
        addedge(s, i, r[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        int x;
        scanf("%d", &x);
        int tsk;
        for (int j = 0; j < x; ++j)
        {
            scanf("%d", &tsk);
            addedge(i, m + tsk, inf);
        }
    }
    ll minc = 0;
    while (set_dep())
    {
        minc += aug(s, 1e15 + 100);
    }
    printf("%lld", ans - minc);
}
