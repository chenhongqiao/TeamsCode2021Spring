class person:
    def __init__(self, score, id):
        self.score = score
        self.id = id


N = int(input())
sc = list(map(int, input().split()))

p = []

for i in range(N):
    p.append(person(sc[i], i))

p.sort(key=lambda x: x.score, reverse=True)

ans = [None] * 100005
rk = 1

for i in range(N):
    ans[p[i].id] = rk
    if i != N - 1 and p[i + 1].score != p[i].score:
        rk = i + 2

for i in range(N):
    print(ans[i], end=" ")

print()
