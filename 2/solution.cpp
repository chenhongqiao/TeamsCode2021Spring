#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v % 2 == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}