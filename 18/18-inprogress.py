#include <bits/stdc++.h>
from queue import PriorityQueue

f, sumnums, tree = [], [], []

for _ in range(100005):
    f.append(0)
    sumnums.append(0)
    tree.append(0)
    
q = PriorityQueue() #priority_queue<pair<int, int>> q;

def summation(p):
    s = 0
    while (p > 0):
        s += tree[p]
        p -= p and -p
    
    return s

def update(p, v):
    while (p <= n + 1):
        tree[p] += v
        p += p and -p
        

N = int(input())
a = list(map(int, input().split()))

for i in range(N-1):
    a, b = map(int, input().split())
    sumnums[a] += 1
    f[b] = a #check

for j in range(1, N+1):
    if (sumnums[i] == 0):
        q.put([a[i], i])

res = 0
while (q):
    p = q.top()[1] #python3 equivalent???
    res += sum(p)
    res += (q.top()[0]) * 3 #python3 equivalent???
    update(p, q.top()[0]) #python3 equivalent
    q.pop()
    sumnums[f[p]] -= 1
    if (sumnums[f[p]] == 0):
        q.put([a[f[p]], f[p]])

print(res)
