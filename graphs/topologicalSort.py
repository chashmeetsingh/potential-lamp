graph = {
    5: [0, 2],
    4: [0, 1],
    2: [3],
    3: [1],
    1: [],
    0: []
}
visited = [False for i in range(len(graph))]

result = [-1 for i in range(len(graph))]
index = len(graph) - 1

def dfs(node):
    stack = [node]

    while len(stack) > 0:
        neighbours = graph[node]

        visited[node] = True
        global index
        popped = stack.pop()
        result[index] = popped
        index -= 1

        for neighbour in neighbours:
            if visited[node] == False:
                dfs(node)


def topologicalSort(graph):
    for i in range(len(graph)):
        if visited[i] == False:
            dfs(i)

    result.reverse()

if __name__ == '__main__':
    topologicalSort(graph)
    print(result)