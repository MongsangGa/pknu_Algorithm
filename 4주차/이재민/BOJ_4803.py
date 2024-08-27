from sys import stdin
from collections import defaultdict

# 복잡한 문제를 해결할 때 해결해야 할 상황을 쪼갠다
# 이번 문제와 같은 경우는 트리 여부와 그 개수를 정확히 세는 것이다
# 1. 트리 세기
#   트리를 세어서 0이면 트리가 없는 것, 있으면 몇 개인지 세는 것
# 2. dfs
#   dfs를 어디에 적용할 것인지를 손으로, 그냥 손코딩으로 먼저 해보자.
#   우선은 dfs를 정확히 사용하는 방법에 대해서도 익히고,
#   재귀적으로 구현할 때 리턴에 대해서도 손으로 써가며 생각하고,
#   최대한 dfs를 사용하는 곳에서 함수로 처리할 수 있게끔 모듈화를 하자.

def dfs(v, graph, visited, parent):
    visited[v] = True
    for neighbor in graph[v]:
        if not visited[neighbor]:
            if not dfs(neighbor, graph, visited, v):
                return False
        elif neighbor != parent:
            return False
    return True

def count_trees(n, graph):
    visited = [False] * (n + 1)
    tree_count = 0
    
    for i in range(1, n + 1):
        if not visited[i]:
            if dfs(i, graph, visited, -1):
                tree_count += 1
                
    return tree_count

case_no = 1

while True:
    n, m = map(int, stdin.readline().split())
    if n == 0 and m == 0:
        break
    
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)
    
    tree_count = count_trees(n, graph)
    
    if tree_count == 0:
        print(f"Case {case_no}: No trees.")
    elif tree_count == 1:
        print(f"Case {case_no}: There is one tree.")
    else:
        print(f"Case {case_no}: A forest of {tree_count} trees.")
    
    case_no += 1
