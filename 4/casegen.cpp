#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n; // digits of the number
    cin >> n;
    string s;
    while (s.length() < n)
    {
        if (s.empty())
        {
            s.push_back(rand(1, 9) + '0');
        }
        else
        {
            s.push_back(rand(0, 9) + '0');
        }
    }
    cout << s << endl;
    return 0;
}