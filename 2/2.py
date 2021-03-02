N = int(input())
card_collections = list(map(int, input().split()))

result = 0
for cards in card_collections:
    if cards % 2 == 0:
        result += 1

print(result)
