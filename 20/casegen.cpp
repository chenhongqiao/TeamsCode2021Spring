#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
string randstr()
{
    int l = rand(1, 6);
    string s;
    for (int i = 0; i < l; i++)
    {
        s.push_back('A' + rand(0, 25));
    }
    return s;
}
unordered_set<string> u;
vector<string> ut;
unordered_map<int, unordered_map<int, bool>> v;
void print(int prufer[], int m)
{
    int vertices = m + 2;
    int vertex_set[vertices];

    for (int i = 0; i < vertices; i++)
    {
        vertex_set[i] = 0;
    }

    for (int i = 0; i < vertices - 2; i++)
    {
        vertex_set[prufer[i] - 1] += 1;
    }
    int j = 0;
    for (int i = 0; i < vertices - 2; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            if (vertex_set[j] == 0)
            {
                vertex_set[j] = -1;
                cout << ut[j] << " " << ut[prufer[i] - 1] << " " << rand(-100, 100) << endl;
                vertex_set[prufer[i] - 1]--;
                break;
            }
        }
    }
    j = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (vertex_set[i] == 0 && j == 0)
        {
            cout << ut[i] << " ";
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
        {
            cout << ut[i] << " " << rand(-100, 100) << endl;
        }
    }
}
void generate(int n)
{
    int length = n - 2;
    int arr[length];

    for (int i = 0; i < length; i++)
    {
        arr[i] = rand(0, length + 1) + 1;
    }
    print(arr, length);
}
int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << endl;
    while (u.size() < n)
    {
        u.insert(randstr());
    }
    for (auto it = u.begin(); it != u.end(); it++)
    {
        ut.push_back(*it);
    }
    generate(n);
    for (int i = 0; i < m; i++)
    {
        cout << ut[rand(0, n - 1)] << " " << ut[rand(0, n - 1)] << endl;
    }

    return 0;
}