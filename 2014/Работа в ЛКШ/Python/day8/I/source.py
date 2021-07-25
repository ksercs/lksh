fin = open("source.in", "r")
fout = open("source.out", "w")
vertex_count = int(fin.readline())
edges = []
source_count = 0
sink_count = 0
source = []
sink = []
zero_count = 0
for i in range(vertex_count):
    edges.append(list(map(int, fin.readline().split())))
for i in range(vertex_count):
    zero_count = 0
    for j in range(vertex_count):
        if edges[i][j] == 0:
            zero_count += 1
        if zero_count == vertex_count:
            sink_count += 1
            sink.append(i + 1)
zero_count = 0
for i in range(vertex_count):
    for j in range(vertex_count):
        if edges[j][i] == 0:
            zero_count += 1
        if zero_count == vertex_count:
            source_count += 1
            source.append(i + 1)  
        if j == vertex_count - 1:
            zero_count = 0
print(source_count, *source, end=' ', file=fout)
print(file=fout)
print(sink_count, *sink, end=' ', file=fout)
fout.close()
