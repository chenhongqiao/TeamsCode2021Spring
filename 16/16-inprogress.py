df = [] 
mp = [] 
res, g = [], [] 
for _ in range(10005):
    res.append(0)
    mp.append(False)
    g.append([])

def bfs(f, fv):
    vis, q = [], []
    for _ in range(10005):
        vis.append(False)
    q.append([f, fv])
    vis[f] = True

    while (q):
        k = q[0]
        res[k[0]] = max(res[k[0]], k[1])
        for i in range(len(g[k[0]])):
            if ((not vis[g[k[0]][i]]) and (not mp[g[k[0]][i]]) and (k[1] / 2 > res[g[k[0]][i]]) and (k[0] != 1)):
                vis[g[k[0]][i]] = True
                q.append([g[k[0]][i], k[1] // 2])
        
        q.pop(0)

ar = []
N, M, Q = map(int, input().split())

for i in range(M):
    f, v = map(int, input().split())
    df.append([f, v])
    mp[f] = True

for _ in range(Q):
    A, B = map(int, input().split())
    g[A].append(B)
    g[B].append(A)

df = sorted(df, key = lambda x: -x[1])

for k in range(len(df)):
    bfs(df[k][0], df[k][1])

for l in range(2, N+1):
    ar.append([l, res[l]])

ar = sorted(ar, key = lambda x: [-x[1], x[0]])

for w in range(len(ar)):
    print("{} {}".format(ar[w][0], ar[w][1])) 




