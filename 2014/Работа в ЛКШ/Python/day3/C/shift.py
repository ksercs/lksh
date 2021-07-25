def sdv(ch):
    global ans
    lboard = 1
    ans = [0] * (len(ch)) 
    ans[0] = ch[len(ch)-1]
    for i in range(len(ch)-1):
        ans[lboard] = ch[i]
        lboard += 1
    return ans


fin = open("shift.in", "r")
fout = open("shift.out", "w")

coun = int(fin.readline())
ch = [int(x) for x in fin.readline().split()]
ch = sdv(ch)
print(*ch, end=' ', file=fout)

fout.close()