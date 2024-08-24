from collections import deque

def bfs(maze, n, m):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    q = deque([(0, 0)])
    maze[0][0] = 1

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if maze[nx][ny] == 1:
                    maze[nx][ny] = maze[x][y] + 1
                    q.append((nx, ny))

    return maze[n-1][m-1]

n, m = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(n)]

print(bfs(maze, n, m))
