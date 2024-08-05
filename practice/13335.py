from collections import deque
from sys import stdin

bridge = deque()
res = 0

n, w, L = map(int, stdin.readline().split())

trucks = list(map(int, stdin.readline().split()))

for i in range(len()):
    pass

for truck in trucks:
    bridge.append(truck)
    if sum(bridge) <= L:
        res += w
        bridge.popleft()
    else:
        bridge.append(truck)

        

print(res)


