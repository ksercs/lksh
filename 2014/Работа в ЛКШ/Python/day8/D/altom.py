fin = open("altom.in", "r")
fout = open("altom.out", "w")

count_vortex = int(fin.readline())
matrix =[[0] * count_vortex for i in range(count_vortex)]

for i in range(count_vortex):
        edges = [int(x) for x in fin.readline().split()]
        for j in edges[1:]:
                matrix[i][j - 1] = 1
        print(*edges)
for line in matrix:
        print(*line, file=fout)
        
fout.close()
