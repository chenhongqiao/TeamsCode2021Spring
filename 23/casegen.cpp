#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n, m, c;
    cin >> n >> m >> c;
    cout << n << " " << m << " " << c << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rand(1, 50);
            if (j != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}