def bfs(graph):
    visited = [False for i in range(len(graph))]

    queue = [0]
    while len(queue) > 0:
        neighbours = graph[queue[0]]

        visited[queue[0]] = True
        # print(queue, neighbours)
        print('Element:', queue.pop(0))

        for neighbour in neighbours:
            if visited[neighbour] == False and neighbour not in queue:
                queue.append(neighbour)

if __name__ == '__main__':        
    graph = {
        0: [1, 2],
        1: [2],
        2: [0, 3],
        3: [3]
    }    

    bfs(graph)