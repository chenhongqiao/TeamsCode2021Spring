#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
unordered_set<int> s;
vector<int> l;
int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(0, m);
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}