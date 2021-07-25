fin = open("half-degree.in", "r")
fout = open("half-degree.out", "w")
vertex_count = int(fin.readline())
edges = []
edge_in =[0] * vertex_count
edge_out = [0] * vertex_count
for i in range(vertex_count):
    edges.append(list(map(int, fin.readline().split())))
for i in range(vertex_count):
    for j in range(vertex_count):
        if edges[i][j] == 1:
            edge_out[i] += 1
            edge_in[j] += 1
            
for i in range(len(edge_in)):
    print(edge_in[i], edge_out[i], file=fout)            
    
fout.close()
