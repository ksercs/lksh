fin = open("mtoal.in", "r")
fout = open("mtoal.out", "w")
edges = []
vertex_count = int(fin.readline())
for i in range(vertex_count):
    edges.append(list(map(int, fin.readline().split())))
for k in range(vertex_count):
    ans = []
    count = 0
    for j in range(vertex_count):
        if edges[k][j] == 1:
            count += 1
            ans.append(j + 1)
    print(count, *ans, file=fout)                              
fout.close()
