#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
umap<long long, int> feq;
vector<long long> c;
int main()
{
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        c.push_back(v);
        feq[v]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += feq[m - c[i]];
    }
    cout << ans / 2 << endl;
    return 0;
}