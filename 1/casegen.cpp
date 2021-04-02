#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    srand(time(0));
    int n; // Max A and B
    cin >> n;
    cout << rand(0, n) << " " << rand(0, n) << endl;
}