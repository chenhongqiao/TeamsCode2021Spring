#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double b, a;
        cin >> b >> a;
        double r = round((a - b) / b * 10000) / 100;
        cout << fixed;
        cout << setprecision(2);
        cout << r << endl;
    }
    return 0;
}