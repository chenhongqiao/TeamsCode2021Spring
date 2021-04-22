#include <bits/stdc++.h>
using namespace std;
#define rand(l, h) (rand() % (h - l + 1) + l)
int main()
{
    srand(time(0));
    int n, k, l;
    cin >> n >> k >> l;
    cout << n << " " << k << " " << l << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ((rand(0, 6) == 3) ? 'S' : 'W');
        }
        cout << endl;
    }
    return 0;
}