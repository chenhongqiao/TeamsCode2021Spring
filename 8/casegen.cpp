#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
string randstr(int l)
{
    string s;
    for (int i = 0; i < l; i++)
    {
        s.push_back(rand(0, 9) + '0');
    }
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
        if (rand(0, 1))
        {
            int kl = rand(2, l);
            string s;
            string l = randstr(kl / 2 - 1);
            string r = l;
            reverse(l.begin(), l.end());
            s += l;
            if (rand(0, 1) || l.length() == 0)
            {
                s.push_back(rand(0, 9) + '0');
            }
            s += r;
            cout << s << endl;
        }
        else
        {
            int kl = rand(2, l);
            string s = randstr(kl);
            cout << s << endl;
        }
    }
    return 0;
}