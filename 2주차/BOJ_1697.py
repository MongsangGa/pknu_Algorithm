from sys import stdin
from collections import deque

n, k = map(int, stdin.readline().split())

def bfs(start):
    dx = [-1, 1, 2]
    q = deque([(start, 0)])
    visited = set([start])

    while q:
        x, time = q.popleft()

        if x == k:
            return time
        
        for i in range(3):
            if i == 2:
                nx = x * dx[i]
            else:
                nx = x + dx[i]


            if 0 <= nx < 100001 and nx not in visited:
                visited.add(nx)
                q.append((nx, time + 1))
    
    return -1


print(bfs(n))

# n-1, n+1, n*2
    

