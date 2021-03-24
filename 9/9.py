N = int(input())

res = 0

for _ in range(N):
    s = input()

    fi, se = "", ""

    for i in range(1, len(s)):
        fi = s[:i]
        se = s[i:]

        if (fi == fi[::-1] and se == se[::-1]):
            res += 1

print(res)