#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cin >> p;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = (s[i] - 'A' + p) % 26 + 'A';
    }
    cout << s << endl;
    return 0;
}