#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n; // number of characters
    int m; // shifting
    cin >> n >> m;
    cout << m << endl;
    string s;
    while (s.length() < n)
    {
        s.push_back(rand(0, 25) + 'A');
    }
    cout << s << endl;
    return 0;
}