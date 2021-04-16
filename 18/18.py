dp = []
for k in range(20250000):
    dp.append([False, False])

dp[20210424][0] = True

for i in range(20210423, -1, -1):
    dp[i][0] = (dp[i+1][1] and dp[i+123][1])
    dp[i][1] = (dp[i+1][0] or dp[i+123][0])

N = int(input())

for i in range(N):
    a = int(input())

    if dp[a][1]:
        print("Yes")
    else:
        print("No")

