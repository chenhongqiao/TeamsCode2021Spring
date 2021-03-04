#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cin >> p;
    string s;
    string tmp;
    while (cin >> tmp)
    {
        s += tmp;
        s += " ";
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            s[i] = (s[i] - 'A' - p) % 26 + 'A';
        }
    }
    cout << s << endl;
    return 0;
}