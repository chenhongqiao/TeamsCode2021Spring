#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    cout << n << endl;
    string s;
    for (int i = 0; i < n; i++)
    {
        s.push_back(rand(0, 25) + 'A');
    }
    cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand(0, i);
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}