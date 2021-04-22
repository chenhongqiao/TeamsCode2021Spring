#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; i++)
    {
        cout << rand(1, n) << " " << rand(1, n) << " " << rand(1, n) << " " << rand(1, n) << endl;
    }
    return 0;
}