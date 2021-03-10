N = int(input())

for _ in range(N):
    A, B = map(float, input().split())
    num = round(((B/A-1)*100), 2)
    s = str(num)
    idx = s.index(".")

    if len(s[idx+1:]) == 1:
        s += "0"
        print(s)
    else:
        print(num)
    


        


