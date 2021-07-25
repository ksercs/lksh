fin = open("lcs.in", "r")
fout = open("lcs.out", "w")
length1 = int(fin.readline())
subsequence1 = list(map(int, fin.readline().split()))
length2 = int(fin.readline().strip())
subsequence2 = list(map(int, fin.readline().split()))
ans = [[0] * (length2 + 1) for i in range(length1 + 1)]
for i in range(1, length1 + 1): 
    for j in range(1, length2 + 1):
        if subsequence1[i - 1] == subsequence2[j - 1]:
            ans[i][j] = ans[i - 1][j - 1] + 1
        else:
            ans[i][j] = max(ans[i][j - 1], ans[i - 1][j])
        
    
print(ans[length1][length2], end=' ', file=fout)

fout.close()