fin = open("count.in", "r")
fout = open("count.out", "w")
vertex_count = int(fin.readline())
edges = [] 
ans = 0
for i in range(vertex_count):
    edges.extend(map(int, fin.readline().split()))
for x in edges:
    if x == 1:
        ans += 1
print(ans // 2,  file=fout)                              
fout.close()

