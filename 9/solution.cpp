#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    string a = s.substr(0, s.length() / 2);
    string b = s.substr(s.length() / 2 + s.length() % 2);
    reverse(b.begin(), b.end());
    return a == b;
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j < s.size(); j++)
        {
            string l = s.substr(0, j);
            string r = s.substr(j);
            if (check(l) && check(r))
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}