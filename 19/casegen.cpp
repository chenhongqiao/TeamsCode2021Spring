#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(1, 20210424) << endl;
    }
    return 0;
}