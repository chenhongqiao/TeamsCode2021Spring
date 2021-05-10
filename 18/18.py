from queue import PriorityQueue

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

q = PriorityQueue() 

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
        q.put([-a[k], k]) 

res = 0

while (not q.empty()):
    top = q.get()
    p = top[1] 
    res += summation(p)
    res += (-top[0]) * 3 
    update_queue(p, -top[0]) 
    snum[f[p]] -= 1

    if (snum[f[p]] == 0):
        q.put([-a[f[p]], f[p]]) 
    
print(res)
