#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long v[105];
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        long long t1 = 0, t2 = 0;
        for (int i = 0; i < m; i++)
        {
            if (v[i] > t1)
            {
                if (t1 > t2)
                {
                    t2 = t1;
                }
                t1 = v[i];
            }
            else if (v[i] > t2)
            {
                t2 = v[i];
            }
        }
        cout << t1 * t2 << endl;
    }
    return 0;
}