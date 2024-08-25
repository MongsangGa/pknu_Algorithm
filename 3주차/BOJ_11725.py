from sys import stdin
from collections import defaultdict, deque

n = int(stdin.readline())
tree = defaultdict(list)

for _ in range(n-1):
    a, b = map(int, stdin.readline().split())
    tree[a].append(b)
    tree[b].append(a)

# BFS를 사용하여 트리 구성
parent = {1: None}
queue = deque([1])

while queue:
    node = queue.popleft()
    for neighbor in tree[node]:
        if neighbor not in parent:
            parent[neighbor] = node
            queue.append(neighbor)

# 부모 노드 출력
for i in range(2, n + 1):
    print(parent[i])
