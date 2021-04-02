#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
string randstr(int l)
{
    string s = "";
    for (int i = 0; i < l; i++)
    {
        int c = rand(0, 2);
        if (c == 0)
        {
            s.push_back(rand(0, 9) + '0');
        }
        else if (c == 1)
        {
            s.push_back(rand(0, 25) + 'a');
        }
        else if (c == 2)
        {
            s.push_back(rand(0, 25) + 'A');
        }
    }
    return s;
}
string parlidrome(int l)
{
    string s;
    string a = randstr(l / 2);
    string b = a;
    reverse(b.begin(), b.end());
    s += a;
    if (l % 2)
    {
        s += randstr(1);
    }
    s += b;
    return s;
}
int main()
{
    srand(time(0));
    int n; // query number
    int l; // string max length
    cin >> n >> l;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int kl = rand(1, l);
        int p = rand(0, kl);
        string s = "";
        if (rand(0, 1))
        {
            s += parlidrome(p);
        }
        else
        {
            s += randstr(p);
        }
        if (rand(0, 1))
        {
            s += parlidrome(kl - p);
        }
        else
        {
            s += randstr(kl - p);
        }
        cout << s << endl;
    }
    return 0;
}