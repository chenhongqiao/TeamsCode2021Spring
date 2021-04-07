#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
short int mz[1005][1005];
int n;
int main()
{
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 && j == 0) || (i == n - 1 && j == n - 1))
            {
                continue;
            }
            if (rand(0, 3) == 3)
            {
                mz[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
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