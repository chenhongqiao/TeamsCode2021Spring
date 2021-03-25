N, target = map(int, input().split())

ar = list(map(int, input().split()))

s = set()
res = 0

for i in range(N):
    find = target - ar[i]

    if find in s:
        res += 1
    
    s.add(ar[i])

print(res)