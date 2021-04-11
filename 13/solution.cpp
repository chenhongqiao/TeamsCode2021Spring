#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
struct person
{
    int id;
    int s;
};
vector<person> p;
bool cmp(const person &a, const person &b)
{
    return a.s > b.s;
}
int ans[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        p.push_back({i, v});
    }
    sort(p.begin(), p.end(), cmp);
    int rk = 1;
    for (int i = 0; i < p.size(); i++)
    {
        ans[p[i].id] = rk;
        if (i != n - 1 && p[i + 1].s != p[i].s)
        {
            rk = i + 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}