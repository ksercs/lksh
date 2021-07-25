from collections import deque
fin = open("interception.in", "r")
fout = open("interception.out", "w")

vertex_count, start_pupil, finish, start_teacher  = [int(x) for x in fin.readline().split()]
graph = [[] for i in range(vertex_count)]
for k in range(vertex_count):
    g = list(map(int, fin.readline().split()))
    for j in range(vertex_count):
        if g[j] == 1:
            graph[k].append(j)

prev1 = [None] * vertex_count
dist1 = [None] * vertex_count
prev2 = [None] * vertex_count
dist2 = [None] * vertex_count
dist1[start_pupil - 1] = 0
dist2[start_teacher - 1] = 0
queue1 = deque()
queue2 = deque()
queue1.append(start_pupil - 1)
queue2.append(start_teacher - 1)
while len(queue1) != 0:
    v = queue1.popleft()
    for u in graph[v]:
        if dist1[u] is None:
            dist1[u] = dist1[v] + 1
            queue1.append(u)
            prev1[u] = v
while len(queue2) != 0:
    v = queue2.popleft()
    for u in graph[v]:
        if dist2[u] is None:
            dist2[u] = dist2[v] + 1
            queue2.append(u)
            prev2[u] = v
if dist1[finish - 1] >= dist2[finish - 1]:
    print("YES", file=fout)
else:
    print("NO", file=fout)
fout.close()