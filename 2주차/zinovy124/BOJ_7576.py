from sys import stdin
from collections import deque

n, m = map(int, stdin.readline().split())
tomato = [list(map(int, stdin.readline().split())) for _ in range(m)]

def bfs():
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    q = deque()
    total_unripe = 0
    
    # 익은 토마토의 위치를 큐에 추가하고 익지 않은 토마토의 수를 셈
    for i in range(m):
        for j in range(n):
            if tomato[i][j] == 1:
                q.append((i, j, 0))  # 위치와 함께 현재 날짜(0일)를 기록
            elif tomato[i][j] == 0:
                total_unripe += 1  # 익지 않은 토마토의 개수

    max_days = 0
    ripe_count = 0
    
    while q:
        x, y, days = q.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < m and 0 <= ny < n and tomato[nx][ny] == 0:
                tomato[nx][ny] = 1
                q.append((nx, ny, days + 1))
                max_days = max(max_days, days + 1)
                ripe_count += 1
    
    if ripe_count != total_unripe:
        return -1  # 모든 토마토가 익지 못하는 경우
    
    return max_days  # 모든 토마토가 익는 데 걸린 시간

# 처음부터 모든 토마토가 익어있는 상태라면 0을 반환
if all(all(t != 0 for t in row) for row in tomato):
    print(0)
else:
    print(bfs())