fin = open("lights.in", "r")
fout = open("lights.out", "w")
n, m = [int(x) for x in fin.readline().split()]

edges = []
ans = [0] * (n + 1)

for i in range(m):
    edges.extend(map(int, fin.readline().split()))
    
for x in edges:
    ans[x] += 1
    
for x in ans[1:]:
    print(x, end=' ', file=fout)
fout.close()
