def dfs(u, visited, colors, color):
    visited[v] = True
    colors[v] = color
    for u in graph[v]:
        if not visited[u]:
            dfs(u, visited, colors, not color)
        elif colors[v] == color:
            is_splitted = False


fin = open("bipartite.in", "r")
fout = open("bipartite.out", "w")
edges = []
color = 
pupils_count, two = [int(x) for x in fin.readline().split()]
for i in range(two):
    edges.append(list(map(int, fin.readline().split()))))
is_plitted = True

for v in range(u):
    if not visited(v):
        dfs(v, visited, colors, True)
        
print(is_splitted, file=fout)
fout.close()



