def summation(p): #long long sum(int p)
    s = 0
    while (p > 0):
        s += tree[p]
        p -= p & (-p)

    return s

def update_queue(p, v): #void update(int p, long long v)
    while (p <= N + 1):
        tree[p] += v
        p += p & (-p)

q = [] #python translation

a, f, snum, tree = [0], [], [], []
N = int(input())

for _ in range(100005):
    f.append(0)
    snum.append(0)
    tree.append(0)

arr = list(map(int, input().split()))
for num in arr:
    a.append(num)

for j in range(N-1): #for (int i = 0; i < n - 1; i++)
    a_num, b = map(int, input().split())
    snum[a_num] += 1
    f[b] = a_num

for k in range(1, N+1): #for (int i = 1; i <= n; i++)
    if (snum[k] == 0):
        q.append([a[k], k]) #python translation?
        q = sorted(q, key = lambda x: -x[0])

res = 0

while (q):
    top = q[0]
    p = top[1] #python translation
    res += summation(p)
    res += (top[0]) * 3 #python translation
    update_queue(p, top[0]) #python translation
    q.pop(0) #python translation
    snum[f[p]] -= 1

    if (snum[f[p]] == 0):
        q.append([a[f[p]], f[p]]) #python translation
        q = sorted(q, key = lambda x: -x[0])
    
print(res)
