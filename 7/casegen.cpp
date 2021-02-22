#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int pow(int f)
{
    int p = 1;
    for (int i = 0; i < f; i++)
    {
        p *= 10;
    }
    return p;
}
int main()
{
    srand(time(0));
    int n;       // query number
    long long m; // maximum cost
    int f;       // maximum decimal points
    cin >> n >> m >> f;
    cout << n << endl;
    m /= 2;
    m *= pow(f);
    for (int i = 0; i < n; i++)
    {
        double b = 1.0 * rand(m / 10, m) / pow(f);
        double a = b + 1.0 * rand(m / 10, m) / pow(f);
        cout << fixed;
        cout << setprecision(f);
        cout << b << " " << a << endl;
    }
    return 0;
}
