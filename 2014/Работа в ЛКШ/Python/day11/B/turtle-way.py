fin = open("turtle-way.in", "r")
fout = open("turtle-way.out", "w")

row, col = [int(x) for x in fin.readline().split()]
acid = []
ans_table = []
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

i = row - 1
j = col - 1
ans_table.append([i, j])
while i != 0 or j != 0:
    if table[i - 1][j] < table[i][j - 1]:
        ans_table.append([i - 1, j])  
        i -= 1
    else:
        ans_table.append([i, j - 1])  
        j -= 1        
    
ans_table.reverse()

print(table[row - 1][col - 1], file=fout)
 
for i in ans_table:
    print(i[0] + 1, i[1] + 1, file=fout)
fout.close()