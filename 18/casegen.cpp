#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
unordered_set<int> v;
unordered_map<int, unordered_map<int, bool>> p;
int main()
{
    srand(time(0));
    int n;
    int m; // m should > n
    cin >> n >> m;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int tmp = rand(1, m);
        while (v.find(tmp) != v.end())
        {
            tmp = rand(1, m);
        }
        v.insert(tmp);
        cout << tmp;
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int a = rand(1, n);
        int b = rand(1, n);
        while (p[a][b] || p[b][a])
        {
            a = rand(1, n);
            b = rand(1, n);
        }
        p[a][b] = true;
        cout << a << " " << b << endl;
    }
}