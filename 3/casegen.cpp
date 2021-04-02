#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
char op[2] = {'+', '-'};
int main()
{
    srand(time(0));
    int n; // number of operations
    int m; // max starting value
    cin >> n >> m;
    cout << n << " " << rand(1, m) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << op[rand(0, 1)] << " " << rand(1, m) << endl;
    }
    return 0;
}