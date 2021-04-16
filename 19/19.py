def dfs(u, ac):
    dp[u] = ac

    for j in range(len(g[u])):
        if g[u][j][0] not in v:
            v[g[u][j][0]] = True
            dfs(g[u][j][0], ac + g[u][j][1])


N, M = map(int, input().split())
rt = ""
g, dp, v = {}, {}, {}

for i in range(N-1):
    a, b, x = map(str, input().split())
    x = int(x)

    if i == 0:
        rt = a
    
    if a not in g:
        g[a] = []
    if b not in g:
        g[b] = []

    g[a].append([b, x])
    g[b].append([a, -x])

v[rt], dp[rt] = True, 0
dfs(rt, 0)

for i in range(M):
    a, b = map(str, input().split())
    print(dp[b] - dp[a])

