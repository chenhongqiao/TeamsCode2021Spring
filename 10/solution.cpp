#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int s, d;
    cin >> s >> d;
    double t = stoi(a.substr(0, 2).c_str()) * 60 + stoi(a.substr(3).c_str());
    t += 1.0 * d / s * 60;
    cout << setfill('0') << setw(2) << ((int)t / 60) % 24 << ":" << setfill('0') << setw(2) << (int)t % 60 << endl;
    return 0;
}