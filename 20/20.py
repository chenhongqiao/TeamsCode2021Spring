N = int(input())
ar = []

for _ in range(N):
    S, E = map(int, input().split())

    if (not ar) or E > ar[-1]:
        ar.append(E)
    else:
        bound = 0

        for i, num in enumerate(ar):
            if E < num:
                bound = i

        ar[i] = E

print(len(ar))


