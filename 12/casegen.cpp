#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    cout << rand(n / 10, n) << endl;
    return 0;
}