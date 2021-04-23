#include <bits/stdc++.h>
using namespace std;
#define rand(l, h) (rand() % (h - l + 1) + l)
unordered_map<int, unordered_map<int, bool>> v;
int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; i++)
    {
        int a = rand(1, n);
        int b = rand(1, n);
        while (v[a][b] || a == b)
        {
            a = rand(1, n);
            b = rand(1, n);
        }
        v[a][b] = true;
        cout << a << " " << b << endl;
    }
    return 0;
}