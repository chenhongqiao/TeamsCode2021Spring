N, M = map(int, input().split())
maze_dist = []
maze_num = []
maze_vis = []

for _ in range(N):
    maze_dist.append([0]*M)
    maze_num.append([0]*M)
    maze_vis.append([0]*M)

maze = []

for _ in range(N):
    maze.append(list(map(int, input().split())))

queue = [(0, 0, 0)]
maze_vis[0][0] = 1
maze_num[0][0] = 1

for i, j, d in queue:

    for x, y in ((i, j+1), (i+1, j), (i-1, j), (i, j-1)):

        if 0 <= x < N and 0 <= y < M and maze[x][y] == 0:
            if maze_vis[x][y] == 0:
                maze_dist[x][y] = d
                maze_num[x][y] = maze_num[i][j]
                maze_vis[x][y] = 1
                queue.append((x, y, d+1))
            elif d == maze_dist[x][y]:
                maze_num[x][y] += maze_num[i][j] 
                maze_num[x][y] = maze_num[x][y] % (10**9+7)
        
print(maze_num[N-1][M-1])

        

