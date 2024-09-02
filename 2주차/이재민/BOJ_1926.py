from sys import stdin
from collections import deque

n, m = map(int, stdin.readline().split())
pic = []
count = 0
max_size = 0
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

been = deque([]) # Queue: append(), popleft()

def bfs(x:int, y:int) -> int:
    c = 1
    been.append((x, y))
    pic[x][y] = 0
    while been:
        cur_x, cur_y = been.popleft()
        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m or pic[nx][ny] == 0:
                continue
            been.append((nx, ny))
            pic[nx][ny] = 0
            c += 1
    
    return c

for i in range(n):
    pic.append(list(map(int, stdin.readline().split())))

for i in range(n):
    for j in range(m):
        if pic[i][j] == 1:
            now_size = bfs(i, j)
            max_size = max(max_size, now_size)
            count += 1

print(count, max_size, sep='\n')


# consider to add count of 1
# 조건 검사는 오른쪽에서 왼쪽으로 하나?

# 문제 어렵게 풀지 말기

# 방문지를 0으로 만들면 됨. -> 방문한 거

# been = deque([]) # queue -> append, popleft
# 방문지 확인하도록 된다. BFS만 하면.

# while queue: 와 같은 식으로 쓸 수 있다. -> 큐가 완전히 빌 때까지