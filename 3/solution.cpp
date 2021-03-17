#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long v;
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        char o;
        long long p;
        cin >> o >> p;
        switch (o)
        {
        case '+':
            v += p;
            break;

        case '*':
            v *= p;
            break;
        case '/':
            v /= p;
            break;
        case '-':
            v -= p;
            break;
        }
    }
    cout << v << endl;
    return 0;
}