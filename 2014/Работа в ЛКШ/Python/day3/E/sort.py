fin = open("sort.in", "r")
fout = open("sort.out", "w")

coun = int(fin.readline())
ch = [int(x) for x in fin.readline().split()]

for i in range(len(ch)):
    pos = 0
    while ch[pos] > ch[i]:
        pos += 1
    ch[pos:] = [ch[i]] + ch[pos:i] + ch[i+1:]
    
print(*ch, end=' ', file=fout)
fout.close()