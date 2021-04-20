#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
short int mz[1005][1005];
int n, m;
int main()
{
    srand(time(0));
    cin >> m >> n;
    cout << m << " " << n << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 && j == 0) || (i == m - 1 && j == n - 1))
            {
                continue;
            }
            if (rand(0, 7) == 7)
            {
                mz[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mz[i][j];
            if (j != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}