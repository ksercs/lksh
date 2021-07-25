fin = open("numbers.in", "r")
fout = open("numbers.out", "w")

ch = int(fin.readline())
ans = 0

for i in range(1, 10 * ch + 1):
    res = (i + 1) - (i - 1)
    if res < 0:
            res = -(res)    
    if res <= 1:
        ans +=1
    print(res, file=fout)

    
#print(ans, file=fout)

fout.close()