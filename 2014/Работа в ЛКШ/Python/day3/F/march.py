fin = open("march.in", "r")
fout = open("march.out", "w")
minim = 2 * (10 ** 9)
ans = [0] * 1000
coun = int(fin.readline())
height= [int(x) for x in fin.readline().split()]

for i in height:
    if i < minim:
        minim = i
for j in range(coun):        
    height[j] -= minim
    
for i in range(len(height)):
    ans[height[i]] += 1
    
for i in range(0, len(ans)):
    for k in range(ans[i]):
        print(i + minim, end=' ', file=fout)

fout.close()