N, num = map(int, input().split())

for _ in range(N):
    s = input()
    op, change = s[0], int(s[2:])

    if op == "+":
        num += change
    elif op == "-":
        num -= change
    elif op == "/":
        num /= change
    else:
        num *= change
    
print(int(num))
