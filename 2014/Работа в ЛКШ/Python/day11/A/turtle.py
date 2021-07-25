fin = open("turtle.in", "r")
fout = open("turtle.out", "w")

row, col = [int(x) for x in fin.readline().split()]
acid = []
for i in range(row):
    acid.append(list(map(int, fin.readline().split())))
table = [[0] * col for i in range(row)]
ans = 0
 
for i in range(row):
    ans += acid[i][0]
    table[i][0] = ans
ans = 0
for j in range(col):
    ans += acid[0][j]
    table[0][j] = ans

for i in range(1, row):
    for j in range(1, col):
        table[i][j] = acid[i][j] + min(table[i - 1][j], table[i][j - 1])
        
print(table[row - 1][col - 1], file=fout)
fout.close()