def summation(p): #long long sum(int p)
    s = 0
    while (p > 0):
        s += tree[p]
        p -= p and -p

    return s

def update(p, v): #void update(int p, long long v)
    while (p <= n + 1):
        tree[p] += v
        p += p and -p

priority_queue<pair<int, int>> q; #python translation

a, f, snum, tree = [0], [], [], []
N = int(input())

for _ in range(100005):
    f.append(0)
    snum.append(0)
    tree.append(0)

for i in range(1, N+1): #for (int i = 1; i <= n; i++) why?
    a.append(int(input()))

for j in range(N-1): #for (int i = 0; i < n - 1; i++)
    a, b = map(int, input().split())
    snum[a] += 1
    f[b] = a

for k in range(1, N+1): #for (int i = 1; i <= n; i++)
    if (snum[k] == 0):
        q.push({a[i], i}) #python translation?

res = 0

while (q):
    p = q.top()[1] #python translation
    res += sum(p)
    res += (q.top()[0]) * 3 #python translation
    update(p, q.top()[0]) #python translation
    q.pop() #python translation
    snum[f[p]] -= 1

    if (snum[f[p]] == 0):
        q.push([a[f[p]], f[p]]) #python translation
    
print(res)
