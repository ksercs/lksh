fin = open("inspection.in", "r")
fout = open("inspection.out", "w")

coun = int(fin.readline())
arr = [int(x) for x in fin.readline().split()]

m1 = m2 = 2 * 10 ** 9
+ 1
for i in arr:
    if i < m1:
        m2 = m1
        m1 = i
    elif i < m2:
        m2 = i
print(m1, m2, end=' ', file=fout)
    
fout.close()