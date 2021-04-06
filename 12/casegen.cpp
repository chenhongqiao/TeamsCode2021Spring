#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
unordered_set<int> lt;
int main()
{
    srand(time(0));
    int n, m, r; // n should <=m
    cin >> n >> m >> r;
    cout << n << " " << m << " " << r << endl;
    for (int i = 0; i < n; i++)
    {
        int p = rand(0, m - 1);
        while (lt.find(p) != lt.end())
        {
            p = rand(0, m - 1);
        }
        lt.insert(p);
        cout << p;
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}