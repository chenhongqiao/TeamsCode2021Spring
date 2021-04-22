#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> seg;
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
    sort(seg.begin(), seg.end());
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto p = s.lower_bound(seg[i].first);
        if (p == s.begin())
        {
            ans++;
        }
        else
        {
            p--;
            s.erase(p);
        }
        s.insert(seg[i].second);
    }
    cout << ans << endl;
    return 0;
}