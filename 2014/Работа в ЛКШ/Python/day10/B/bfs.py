from collections import deque
fin = open("bfs.in", "r")
fout = open("bfs.out", "w")

vertex_count, start, finish = [int(x) for x in fin.readline().split()]
graph = [[] for i in range(vertex_count)]
for k in range(vertex_count):
    g = list(map(int, fin.readline().split()))
    for j in range(vertex_count):
        if g[j] == 1:
            graph[k].append(j)

prev = [None] * vertex_count
dist = [None] * vertex_count
dist[start - 1] = 0
queue = deque()
queue.append(start - 1)
while len(queue) != 0:
    v = queue.popleft()
    for u in graph[v]:
        if dist[u] is None:
            dist[u] = dist[v] + 1
            queue.append(u)
            prev[u] = v
if dist[finish - 1] is None:
    print('0', file=fout)
else:
    print(dist[finish - 1], file=fout)
fout.close()