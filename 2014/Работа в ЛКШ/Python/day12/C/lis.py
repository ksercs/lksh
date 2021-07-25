fin = open("lis.in", "r")
fout = open("lis.out", "w")

length = int(fin.readline())
subsequence = list(map(int, fin.readline().split()))
lis = [1] * length
ans = []

for i in range(length):
    for prev in range(i):
        if subsequence[prev] < subsequence[i] and lis[prev] >= lis[i]:
            lis[i] = lis[prev] + 1    
print(max(lis), end=' ', file=fout)

fout.close()