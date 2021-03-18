N = int(input())


for i in range(2, int(N**0.5)):
    power = 0

    if N % i == 0:
        while N % i == 0:
            N /= i
            power += 1
    
    print("{} {}".format(i, power))

