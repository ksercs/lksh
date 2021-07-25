fin = open("diagonal.in", "r")
fout = open("diagonal.out", "w")

ch = int(fin.readline())
matrix = []
main_sum = 0
summ = 0
for i in range(ch):
    matrix.append(list(map(int, fin.readline().split())))
for i in range(ch):
    for j in range(ch):
        if i == j:
            main_sum += matrix[i][j]
        if i == ch - j - 1:
            summ += matrix[i][j]
print(main_sum, summ, end=' ', file=fout)
fout.close()