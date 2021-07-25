fin = open("check.in", "r")
fout = open("check.out", "w")
vertex_count, edges_count = [int(x) for x in fin.readline().split()]
ans = False
matrix = [[0] * vertex_count for i in range(vertex_count)]  
for i in range(edges_count):
    u, v = list(map(int, fin.readline().split()))
    u -= 1
    v -= 1
    if matrix[u][v] == 1:
        ans = True
    matrix[u][v] = 1
    # matrix[v][u] = 1
if ans:
    print('YES', file=fout)
else:
    print('NO',  file=fout)                              
fout.close()
