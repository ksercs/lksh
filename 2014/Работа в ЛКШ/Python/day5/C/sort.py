def merge(a, b):
    i = 0
    j = 0
    c = []
    while len(a) > i and len(b) > j:
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    return c + a[i:] + b[j:]
        

def merge_sort(a):
    if len(a) <= 1:
        return a
    else:
        left = a[:len(a) // 2]
        right = a[len(a) // 2:]
    return merge(merge_sort(left), merge_sort(right))
        
        
fin = open("sort.in", "r")
fout = open("sort.out", "w")
coun = int(fin.readline())
ch = [int(x) for x in fin.readline().split()]
ans = merge_sort(ch)
print(*ans, end=' ', file=fout)
    
fout.close()