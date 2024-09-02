from sys import stdin

def find_link_dfs(graph, start):
    stack = [start]
    visited = set()
    infected_count = 0

    while stack:
        v = stack.pop()

        if v not in visited:
            visited.add(v)
            infected_count += 1

            for neighbor in reversed(graph[v]):
                if neighbor not in visited:
                    stack.append(neighbor)

    return infected_count - 1

n = int(stdin.readline())
pair_count = int(stdin.readline())

graph = {i: [] for i in range(1, n+1)}

for _ in range(pair_count):
    u, v = map(int, stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

result = find_link_dfs(graph, 1)
print(result)
