#include <bits/stdc++.h>
using namespace std;
vector<int> l;
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    l.push_back(-r - 1);
    l.push_back(m + r);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        l.push_back(p);
    }
    sort(l.begin(), l.end());
    int ans = 0;
    for (int i = 1; i < l.size(); i++)
    {
        if (l[i] - l[i - 1] - 1 > r * 2)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}