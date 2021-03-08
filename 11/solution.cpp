#include <bits/stdc++.h>
using namespace std;
vector<int> op;
string s;
int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        op.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        s[i] = s[i - op[i]];
    }
    cout << s << endl;
    return 0;
}