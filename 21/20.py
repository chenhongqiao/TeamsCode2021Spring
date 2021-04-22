N = int(input())
start_pos = []
s = []

for i in range(N):
    start_pos.append(list(map(int, input().split())))

start_pos = sorted(start_pos)

for tup in start_pos:
    s.append(tup[1])

res = 1
slow = s[N-1]
for i in range(N-1, -1, -1):
    if s[i] < slow:
        res += 1
    slow = min(slow, s[i])

print(res)
