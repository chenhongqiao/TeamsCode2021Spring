N = int(input())

for i in range(2, int(N**0.5)):
    power = 0

    if N % i == 0:
        while N % i == 0:
            N /= i
            power += 1

    if power != 0:
        print("{} {}".format(i, power))

if N != 1:
    print("{} 1".format(int(N)))
