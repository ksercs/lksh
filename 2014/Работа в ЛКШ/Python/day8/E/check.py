fin = open("check.in", "r")
fout = open("check.out", "w")
vertex_count = int(fin.readline())
edges = [] 
ans = 0
for i in range(vertex_count):
    edges.append(list(map(int, fin.readline().split())))
for i in range(vertex_count):
    for j in range(vertex_count):
        if edges[i][j] != edges[j][i] or edges[i][i] != 0:
            ans = 1
            break
    
if ans == 0:
    print('YES',  file=fout)
else:
    print('NO',  file=fout)
    
fout.close()

