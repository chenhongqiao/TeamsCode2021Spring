N, num_blocks, radius = map(int, input().split())
ar = list(map(int, input().split()))

ar = sorted(ar)

res = 0

if ar[0] - radius > 0:
    res += 1

for i in range(N):
    if ar[i] + radius > num_blocks - 1:
        break

    if i == N - 1:
        if (ar[i] + radius <= num_blocks - 1):
            res += 1
        break
    else:
        if (ar[i] + radius + 1 < ar[i+1] - radius):
            res += 1

print(res)
