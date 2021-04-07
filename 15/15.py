from collections import deque

N = int(input())
maze = []
done = False

for _ in range(N):
    maze.append(list(map(int, input().split())))

if maze[0][0] or maze[N-1][0]:
    print(-1)

queue = [(0, 0, 1)]
maze[0][0] = 1

for i, j, d in queue:
    if i == N-1 and j == 0:
        print(d-1)
        done = True
        break

    for x, y in ((i-1, j), (i, j-1), (i, j+1), (i+1, j)):
        if 0 <= x < N and 0 <= y < N and not maze[x][y]:
            maze[x][y] = 1
            queue.append((x, y, d+1))

if not done:
    print(-1)
