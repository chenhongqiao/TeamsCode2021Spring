N = int(input())
s = input()
ar = list(map(int, input().split()))

for i in range(N):
    s = s.replace(s[i], s[i - ar[i]])

print(s)