def subset_k(count, max_count, prefix):
    global ans
    if max_count == 0:
        ans += 1
    else:
        if len(prefix) == 0:
            nextt = 1
        else:
            nextt = prefix[-1] + 1
        while nextt + max_count - 1 <= count:
            subset_k(count, max_count - 1, prefix + [nextt])
            nextt += 1
            
fin = open("jeopardy.in", "r")
fout = open("jeopardy.out", "w")
count = int(fin.readline())
max_count = 5
ans = 0
for i in range(max_count + 1):
    subset_k(count, i, [])
print(ans, file=fout)
fout.close()