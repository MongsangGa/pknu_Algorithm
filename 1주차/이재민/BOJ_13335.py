from collections import deque
from sys import stdin

bridge = deque()
cur_w, sec = 0, 0

n, w, L = map(int, stdin.readline().split())

trucks = list(map(int, stdin.readline().split()))

for i in range(n):
    while True:
        if len(bridge) == w:
            cur_w -= bridge.popleft()
        if cur_w + trucks[i] <= L:
            break
        bridge.append(0)
        sec += 1
    bridge.append(trucks[i])
    cur_w += trucks[i]
    sec += 1

print(sec + w)

# bridge는 덱(deque)
# cur_w는 현재 다리에 올라온 트럭들 무게의 총합
# sec는 시간
# 반복문 진입 후 break로 이동함, 그 후 19번 줄에서 다리에 i번째 트럭 올림
# 현재 다리에 올라온 총 트럭 무게의 합에 i번째 트럭 무게 더함
# 시간 1 증가
# 다리의 길이만큼 트럭이 올라갔는지 14번에서 검사
# 가장 앞의 트럭이 15번에서 나감
# 15번은 다리의 최대하중을 넘는지 검사 안넘으면 트럭이 들어갈 수 있으므로 break
# sec + w의 이유는 sec은 마지막 트럭이 다리에 올라오는 시간까지를 잰 것이며
# w는 그 마지막 트럭까지 다리를 다 지나간 후의 시간이므로.
# ----- 회고
# 큐를 써야 할 것 같다는 느낌만 왔었는데, 답안지처럼 수려하게 큐를 쓰진 못하고
# 계속 쩔쩔매다가 그냥 답안지를 보게 됐습니다.
# 애초에 문제를 생각하는 시간이 너무 길어지고, 중간에 집중을 끊어버려서
# 문제를 푸는 데에 시간이 많이 걸렸습니다.
# 문제를 풀 때는 정말 다른 일에 신경쓰지 않고 문제만 풀도록 해야겠습니다.