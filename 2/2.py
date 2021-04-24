N = int(input())
card_collections = list(map(int, input().split()))

result = 0
for cards in card_collections:
    print(cards % 3, end=" ")

print()
