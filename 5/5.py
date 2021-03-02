shift = int(input())
change = input()

alphabet = "ABCDEFGHIJKLMNOPQRSTUVXYZ"

idx = 0
result = ""

for c in change:
    if c != " ":
        idx = (alphabet.find(c) - shift) % 26
        result += alphabet[idx]
    else:
        result += " "

print(result)

