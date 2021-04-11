#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
string randstr()
{
    int l = rand(1, 6);
    string s;
    for (int i = 0; i < l; i++)
    {
        s.push_back('A' + rand(0, 25));
    }
    return s;
}
unordered_set<string> u;
vector<string> ut;
unordered_map<int, unordered_map<int, bool>> v;
int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    while (u.size() < n)
    {
        u.insert(randstr());
    }
    for (auto it = u.begin(); it != u.end(); it++)
    {
        ut.push_back(*it);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a = rand(0, n - 1);
        int b = rand(0, n - 1);
        while (v[a][b] || v[b][a] || a == b)
        {
            a = rand(0, n - 1);
            b = rand(0, n - 1);
        }
        v[a][b] = true;
        cout << ut[a] << " " << ut[b] << " " << rand(-100, 100) << endl;
    }
    for (int i = 0; i < m; i++)
    {
        cout << ut[rand(0, n - 1)] << " " << ut[rand(0, n - 1)] << endl;
    }

    return 0;
}