#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n;
    int m;
    cin >> n >> m;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int a = rand(1, m);
        int b = rand(1, m);
        cout << min(a, b) << " " << max(a, b) << endl;
    }
    return 0;
}