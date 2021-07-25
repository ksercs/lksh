fin = open("countsort.in", "r")
fout = open("countsort.out", "w")

coun = int(fin.readline())
ch = [int(x) for x in fin.readline().split()]

ans = [0] * 10005

for i in range(len(ch)):
    ans[ch[i]] += 1
    
for i in range(0, 10005):
    for k in range(ans[i]):
        print(i, end=' ', file=fout)
    
fout.close()