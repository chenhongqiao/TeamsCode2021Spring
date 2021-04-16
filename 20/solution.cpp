#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> seg;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        seg.push_back({a, b});
    }
    sort(seg.begin(), seg.end(), cmp);
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto p = s.upper_bound(seg[i].second);
        if (p == s.end())
        {
            ans++;
        }
        else
        {
            s.erase(p);
        }
        s.insert(seg[i].second);
    }
    cout << ans << endl;
    return 0;
}