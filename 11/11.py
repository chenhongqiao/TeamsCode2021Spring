N = int(input())
s = input()
ar = list(map(int, input().split()))

for i in range(N):
    s = s[:i] + s[i - ar[i]] + s[i+1:]

print(s)
