df, mp, res, g = [], [], [], []

for _ in range(10005):
    mp.append(0)
    res.append(0)
    g.append(0)

def cmp1(a, b):
    return a[1] > b[1]

def cmp2(a, b):
    if (a[1] == b[1]):
        return a[0] < b[0]

    return a[1] > b[1]

def bfs(f, fv):
    vis = []
    for _ in range(10005):
        vis.append(False)

    q = []
    q.append([f, fv])
    vis[f] = True
    while (q):
        k = q[0]
        res[k[0]] = max(res[k[0]], k[1])

        for i in range(len(g[k[0]])):
            if ((not vis[g[k[0]][i]]) and (not mp[g[k[0]][i]]) and (k[1] / 2 > ans[g[k[0]][i]]) and (k[0] != 1)):
                vis[g[k[0]][i]] = True
                q.append([g[k[0]][i], k[1] / 2])

        q.pop()
    
ar = []

N, M, Q = map(int, input().split())

for i in range(M):
    f, v = map(int, input().split())
    df.append([f, v])
    mp[f] = True

for j in range(Q):
    a, b = map(int, input().split())
    g[a].append(b) #why do you push back to a int array?
    g[b].append(a) #why do you push back to a int array?

sort(df.begin(), df.end(), cmp1) #python3 equivalent?

for k in range(len(df)):
    bfs(df[i][0], df[i][1])

for l in range(2, N+1):
    ar.append([i, res[i]])

sort(ar.begin(), ar.end(), cmp2); #python3 equivalent?
 
for c in range(len(ar)):
    print("{} {}".format(ar[i][0], ar[i][1]))


