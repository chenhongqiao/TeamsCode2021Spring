N, M = map(int, input().split())
res = 0
st = []
g, v = {}, {}
for id in range(N+1):
    g[id] = {}
    v[id] = {}
    for j in range(N+1):
        g[id][j] = []
        v[id][j] = False

def bfs(x, y):
    q = []
    q.append([x, y])
    cnt = 1
    while q:
        kx, ky = q[0][0], q[0][1]

        for i in range(len(g[kx][ky])): #(int i = 0; i < g[kx][ky].size(); i++)
            nx, ny = g[kx][ky][i][0], g[kx][ky][i][1]

            if (not v[nx][ny]):
                v[nx][ny] = True
                q.append([nx, ny])
                cnt += 1
            
        q.pop(0)

    return cnt * (cnt - 1) #return ((long long)cnt) * (cnt - 1);

for _ in range(M): #(int i = 0; i < m; i++)
    x1, y1, x2, y2 = map(int, input().split())
    g[x1][y1].append([x2, y2])
    g[x2][y2].append([x1, y1])
    st.append([x1, y1])
    st.append([x2, y2])

res = N * N

for j in range(len(st)): #(int i = 0; i < st.size(); i++)

    if (not v[st[j][0]][st[j][1]]):
        v[st[j][0]][st[j][1]] = True
        res += bfs(st[j][0], st[j][1])

print(res)

