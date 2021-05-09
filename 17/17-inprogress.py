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

    while (q):
        kx, ky = q[0][0], q[0][1]

        for idx in range(len(g[kx][ky])):
            nx, ny = g[kx][ky][idx][0], g[kx][ky][idx][1]
        
            if (not v[nx][ny]):
                v[nx][ny] = True
                q.append([nx, ny])
                cnt += 1
    
        q.pop(0)
    
    return (cnt) * (cnt - 1)

for _ in range(M):
    x1, x2, y1, y2 = map(int, input().split())
    g[x1][y1].append([x2, y2])
    g[x2][y2].append([x1, y1])
    st.append([x1, y1])
    st.append([x2, y2])

res = N*N
for i in range(len(st)):
    if (not v[st[i][0]][st[i][1]]):
        v[st[i][0]][st[i][1]] = True
        res += bfs(st[i][0], st[i][1])

print(res)
