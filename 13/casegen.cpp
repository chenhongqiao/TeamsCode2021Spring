#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
unordered_set<int> s;
vector<int> l;
int main()
{
    srand(time(0));
    int n, m; // n should <=m
    cin >> n >> m;
    cout << n << " " << m << " " << endl;
    for (int i = 0; i < n; i++)
    {
        int a = rand(0, m);
        while (s.find(a) != s.end())
        {
            a = rand(0, m);
        }
        s.insert(a);
        cout << a;
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}