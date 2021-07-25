def dfs(u):
    visited[u] = True
    for v in graph[u]:
        if not visited[v]:
            print(u, v, file=fout)
            dfs(v)
            


fin = open("tree.in", "r")
fout = open("tree.out", "w")

vertex_count, edges_count = list(map(int, fin.readline().split()))

visited = [False] * (vertex_count + 1)

graph = [[] for x in range(vertex_count + 1)]

for i in range(edges_count):
    x, y = list(map(int, fin.readline().split()))
    graph[x].append(y)
    graph[y].append(x)
    
dfs(1)
fout.close()



