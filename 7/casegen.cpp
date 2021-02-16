#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n; // query number
    int m; // items per query
    int t; // maximum value in query
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << rand(0, t) << " ";
        }
        cout << endl;
    }
    return 0;
}