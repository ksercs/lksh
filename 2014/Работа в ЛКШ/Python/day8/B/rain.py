fin = open("rain.in", "r")
fout = open("rain.out", "w")
mountain_count = int(fin.readline())
bridge = []
ans = 0
for i in range(mountain_count):
    bridge.append(list(map(int, fin.readline().split())))
colour = [int(x) for x in fin.readline().split()]

for i in range(len(bridge)):
    for j in range(i + 1):
        if bridge[i][j] == 1 and colour[i] != colour[j]:
            ans += 1   
print(ans, file=fout)

fout.close()
