N, M = map(int, input().split())

for _ in range(N):
    ar = list(map(int, input().split()))

    ar = sorted(ar)

    if len(ar) > 1:
        print(ar[-1] * ar[-2])
    else:
        print(ar[0])