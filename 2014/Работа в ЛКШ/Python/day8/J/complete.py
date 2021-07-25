fin = open("complete.in", "r")
fout = open("complete.out", "w")
vertex_count, edges_count = list(map(int,fin.readline().split()))
one_count = 0

matrix =[[0] * vertex_count for i in range(vertex_count)]

for i in range(edges_count):
        x, y = [int(x) for x in fin.readline().split()]
        matrix[x - 1][y - 1] = 1
        matrix[y - 1][x - 1] = 1

for i in range(vertex_count):
        one_count += sum(matrix[i])

if one_count == vertex_count ** 2 - vertex_count:
        print("YES", file=fout)
else:
        print("NO", file=fout)
fout.close