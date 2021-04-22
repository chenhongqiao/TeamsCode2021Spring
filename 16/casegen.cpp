#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int v[1005][1005];
int vl[1005];
int main()
{
    srand(time(0));
    int n, m, q;
    cin >> n >> m >> q;
    cout << n << " " << m << " " << q << endl;
    for (int i = 0; i < m; i++)
    {
        int a = rand(1, n);
        while (vl[a])
        {
            a = rand(1, n);
        }
        vl[a] = true;
        cout << a << " " << rand(1, 100000) << endl;
    }

    for (int i = 0; i < q; i++)
    {
        int a = rand(1, n);
        int b = rand(1, n);
        while (v[a][b] || v[b][a] || a == b)
        {
            a = rand(1, n);
            b = rand(1, n);
        }
        v[a][b] = true;
        cout << a << " " << b << " " << endl;
    }
    return 0;
}