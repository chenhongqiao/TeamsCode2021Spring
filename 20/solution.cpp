#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int f[100005];
int snum[100005];
priority_queue<pair<int, int>> q;
int tree[100005];
int sum(int p)
{
    int s = 0;
    while (p > 0)
    {
        s += tree[p];
        p -= p & -p;
    }
    return s;
}
int update(int p, int v)
{
    while (p <= n + 1)
    {
        tree[p] += v;
        p += p & -p;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        snum[a]++;
        f[b] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        if (snum[i] == 0)
        {
            q.push({a[i], i});
        }
    }
    long long ans = 0;
    while (!q.empty())
    {
        int p = q.top().second;
        ans += sum(p);
        ans += (q.top().first) * 3;
        update(p, q.top().first);
        q.pop();
        snum[f[p]]--;
        if (snum[f[p]] == 0)
        {
            q.push({a[f[p]], f[p]});
        }
    }
    cout << ans << endl;
    return 0;
}