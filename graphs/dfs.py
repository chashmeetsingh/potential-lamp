graph = {
    0: [1, 2],
    1: [2],
    2: [0, 3],
    3: [3]
}

visited = [False for i in range(len(graph))]

def dfs(node):
    stack = [graph[0]]

    while len(stack) > 0:
        neighbours = graph[node]

        if visited[node]: return

        visited[node] = True
        print(node)
        for neighbour in neighbours:
            if visited[neighbour] == False:
                dfs(neighbour)

if __name__ == '__main__':
    dfs(0)