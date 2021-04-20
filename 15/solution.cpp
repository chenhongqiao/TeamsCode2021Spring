#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
int n, m;
umap<int, umap<long long, pair<int, int>>> pw;
short int mz[1005][1005];
struct node
{
    int x, y;
    int s;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mz[i][j];
            pw[i][j] = {0, -1};
        }
    }
    queue<node> q;
    pw[0][0] = {1, 0};
    q.push({0, 0, 0});
    while (!q.empty())
    {
        node k = q.front();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + k.x;
            int ny = dy[i] + k.y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && mz[nx][ny] != 1)
            {
                if (pw[nx][ny].second == -1)
                {
                    pw[nx][ny] = {pw[k.x][k.y].first, k.s};
                    q.push({nx, ny, k.s + 1});
                }
                else if (k.s == pw[nx][ny].second)
                {
                    pw[nx][ny].first += pw[k.x][k.y].first;
                    pw[nx][ny].first %= 1000000007;
                }
            }
        }
        q.pop();
    }
    cout << pw[m - 1][n - 1].first << endl;
    return 0;
}