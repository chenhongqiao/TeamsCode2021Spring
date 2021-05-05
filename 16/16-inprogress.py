def cmp1(a, b): #(pair<int, int> a, pair<int, int> b)
    return a[1] > b[1]

def cmp2(a, b): #(pair<int, int> a, pair<int, int> b)
    if (a[1] == b[1]):
        return a[0] < b[0]

    return a[1] > b[1]

def bfs(f, v): #(int f, int fv)
    vis = [] #bool vis[10005] = {false}
    for _ in range(10005):
        vis.append(False)

    q = []
    q.append([f, fv])
    vis[f] = True

    while (q):
        k = q[0]
        res[k[0]] = max(ans[k[0]], k[1])
        for i in range(len(g[k[0]])):
            if ((not vis[g[k[0]][i]]) and (not mp[g[k[0]][i]]) and (k[1] / 2 > res[g[k[0]][i]]) and (k[0] != 1)):
                vis[g[k[0]][i]] = True
                q.append([g[k[0]][i], k[1] / 2])
        
        q.pop()

vector<int> g[10005] #python translation?

ar = [] #vector<pair<int, int>> ar;
df = [] #vector<pair<int, int>> df;
N, M, Q = map(int, input().split())
mp, res = [], [] #bool mp[10005]; int ans[10005] = {0};
for _ in range(10005): 
    mp.append(False)
    res.append(0)

for i in range(M):
    f, v = map(int, input().split())
    df.append([f, v])
    mp[f] = True
}

for j in range(Q):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

sort(df.begin(), df.end(), cmp1) #python translation plz

for k in range(len(df)):
    bfs(df[i][0], df[i][1])

for l in range(2, N+1):
    ar.append([i, ans[i]])

sort(ar.begin(), ar.end(), cmp2); #python translation plz

for c in range(len(ar)):
{
    print("{} {}".format(ar[i][0], ar[i][1])
}
