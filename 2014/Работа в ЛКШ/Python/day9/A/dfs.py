def dfs(u):
    visited[u] = True
    for v in range(vertex_count):
        if not visited[v] and graph[u][v] == 1:
            dfs(v)            


fin = open("dfs.in", "r")
fout = open("dfs.out", "w")

vertex_count, vertex = [int(x) for x in fin.readline().split()]
count = 0
graph = []
visited = [False] * vertex_count
for i in range(vertex_count):
    graph.append(list(map(int, fin.readline().split())))
    
dfs(vertex - 1)
ans = visited.count(True)

print(ans, file=fout)
fout.close()

