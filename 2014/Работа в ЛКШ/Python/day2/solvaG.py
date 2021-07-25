a, b = [int(x) for x in input().split()]
arr = [True] * (b + 1)

for i in range(2, b + 1):
    for j in range(i, b // i + 1):        
        arr[i*j] = False        
    
for k in range (a, b + 1):
    if arr[k] == True:
        if k != 1:
            print(k, end = ' ')