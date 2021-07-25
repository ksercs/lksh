def dfs(v, visited, parent):
    global is_cyclic
    visited[v] = Blue
    for u in range(vertex_count):
        if not visited[u] == WHITE:
            dfs(u, visited, v)
        elif u != parent and visited[u] == BLUE:
            ic_cyclic = True
            visited[v] = RED


fin = open("cycle.in", "r")
fout = open("cycle.out", "w")

vertex_count, edge_count = list(map(int, fin.readline().split()))
edge = []
WHITE = 0
BLUE = 1
RED = 2
is_cyclic = False
edges = []

for i in range(edge_count):
    u, v = list(map(int, fin.readline().split()))
    u -= 1
    v -= 1
    edges.append([u, v])
    
if is_cyclic:
    print('YES', file=fout)
else:
    print('NO', file=fout)
    
fout.close()
