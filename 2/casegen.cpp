#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n; // number of stacks
    int m; // max of each stack
    cin >> n >> m;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(1, m);
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}