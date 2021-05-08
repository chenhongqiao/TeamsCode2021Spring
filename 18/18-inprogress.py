def summation(p): 
    s = 0
    while (p > 0):
        s += tree[p]
        p -= p & (-p)

    return s

def update_queue(p, v): 
    while (p <= N + 1):
        tree[p] += v
        p += p & (-p)

q = [] 
a, f, snum, tree = [0], [], [], []
N = int(input())

for _ in range(100005):
    f.append(0)
    snum.append(0)
    tree.append(0)

arr = list(map(int, input().split()))
for num in arr:
    a.append(num)

for j in range(N-1): 
    a_num, b = map(int, input().split())
    snum[a_num] += 1
    f[b] = a_num

for k in range(1, N+1): 
    if (snum[k] == 0):
        q.append([a[k], k]) 
        q = sorted(q, key = lambda x: -x[0])

res = 0

while (q):
    top = q[0]
    p = top[1] 
    res += summation(p)
    res += (top[0]) * 3 
    update_queue(p, top[0]) 
    q.pop(0) 
    snum[f[p]] -= 1

    if (snum[f[p]] == 0):
        q.append([a[f[p]], f[p]])
        q = sorted(q, key = lambda x: -x[0])
    
print(res)
