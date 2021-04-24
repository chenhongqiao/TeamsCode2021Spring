#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int v[10005][10005];
int vl[10005];
vector<pair<int, int>> g;
int main()
{
    srand(time(0));
    int n, m, q;
    cin >> n >> m >> q;
    cout << n << " " << m << " " << q << endl;
    for (int i = 0; i < m; i++)
    {
        int a = rand(2, n);
        while (vl[a])
        {
            a = rand(2, n);
        }
        g.push_back({1, a});
        vl[a] = true;
        cout << a << " " << rand(1, 100000) << endl;
    }

    while (g.size() < q)
    {
        int a = rand(2, n);
        int b = rand(2, n);
        while (v[a][b] || v[b][a] || a == b)
        {
            a = rand(2, n);
            b = rand(2, n);
        }
        v[a][b] = true;
        g.push_back({a, b});
    }

    for (int i = 0; i < q; i++)
    {
        cout << g[i].first << " " << g[i].second << endl;
    }
    return 0;
}