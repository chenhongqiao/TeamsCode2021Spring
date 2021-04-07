#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    const int nrt = sqrt(n);
    for (int i = 2; i <= nrt + 1; i++)
    {
        int cnt = 0;
        while (n > 0 && n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt != 0)
        {
            cout << i << " " << cnt << endl;
        }
    }
    if (n != 1)
    {
        cout << n << " " << 1 << endl;
    }
    return 0;
}