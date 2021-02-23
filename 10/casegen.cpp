#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
int main()
{
    int s; // Max S
    int d; // Max D
    cin >> s >> d;
    cout << setfill('0') << setw(2) << rand(0, 23) << ":" << setfill('0') << setw(2) << rand(0, 59) << endl;
    cout << rand(1, s) << " " << rand(0, d) << endl;
    return 0;
}