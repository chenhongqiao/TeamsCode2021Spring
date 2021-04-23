#include <bits/stdc++.h>
using namespace std;
#define rand(l, h) (rand() % (h - l + 1) + l)
int main()
{
    srand(time(0));
    int n, m, t;
    cin >> n >> m >> t;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(5, 1000000);
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(5, 1000000);
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        int tk = rand(1, t);
        cout << tk << " ";
        for (int j = 0; j < tk; j++)
        {
            cout << rand(1, n);
            if (j != tk - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}