def dfs(u):
    visited[u] = True
    for i in range(vertex_count):
        if not visited[i] and graph[u][i] == 1:
            dfs(i)            


fin = open("components.in", "r")
fout = open("components.out", "w")
vertex_count = int(fin.readline())
graph = []
visited = [False] * vertex_count

for i in range(vertex_count):
    graph.append(list(map(int, fin.readline().split())))
    
count = 0
for v in range(vertex_count):
    if not visited[v]:
        dfs(v)
        count += 1
        
print(count, file=fout)
fout.close()

