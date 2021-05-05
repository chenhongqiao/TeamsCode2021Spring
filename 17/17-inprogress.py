def bfs(x, y):
    q = []
    q.append([x, y])
    cnt = 1

    while (q):
        kx = q[0][0]
        ky = q[0][1]
        for i in range(len(g[kx][ky])):
            nx = g[kx][ky][i][0]
            ny = g[kx][ky][i][1]
            if (not v[nx][ny]):
                v[nx][ny] = True
                q.append([nx, ny])
                cnt += 1

        q.pop()

    return (cnt * (cnt - 1))

N, M = map(int, input().split())
res = 0
st = [] #vector<pair<int, int>> st;
umap<int, umap<int, vector<pair<int, int>>>> g; #this
umap<int, umap<int, bool>> v; #this

for i in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    g[x1][y1].append([x2, y2])
    g[x2][y2].append([x1, y1])
    st.append([x1, y1])
    st.append([x2, y2])

res = n * n
for j in range(len(st)):
    if (not v[st[i][0]][st[i][1]])
    {
        v[st[i][0]][st[i][1]] = True
        res += bfs(st[i][0], st[i][1])
    }

print(res)

