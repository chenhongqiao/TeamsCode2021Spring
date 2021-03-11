// SOLUTION NEEDS TO BE REWRITE TO ADAPT NEW CONTEXT
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2 + s.length() % 2);
        reverse(b.begin(), b.end());
        if (a == b)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    return 0;
}