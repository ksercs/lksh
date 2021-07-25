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


fin = open("dictionary.in", "r")
fout = open("dictionary.out", "w")
words = []
count = int(fin.readline())
ans = [] * count
help = [True] * count
for i in range(count):
    word = fin.readline().strip()
    words.append(word)

ans = merge_sort(words)
        
for i in range(count):
    for j in range(i+1, count):
        if ans[i] == ans[j]:
            help[j] = False
for i in range(count):
    if help[i] == True:
        print(ans[i], file=fout)

fout.close()