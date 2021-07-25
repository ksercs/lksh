fin = open("sort.in", "r")
fout = open("sort.out", "w")

n = int(fin.readline())
arr = [int(x) for x in fin.readline().split()]

for i in range(n - 1):
    for j in range(n - i - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]            
for k in range(len(arr)):
    print(arr[k], end=' ', file=fout)
  
fout.close()