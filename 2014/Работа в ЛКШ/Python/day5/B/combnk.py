def subset_k(pos, count):
    if pos == str_count:
        print(*ans, sep='', file=fout)
    else:
        if len(ans) - pos > one_count - count:
            ans[pos] = 0
            subset_k(pos + 1, count)        
        if count < one_count:
            ans[pos] = 1
            subset_k(pos + 1, count + 1)
            
            
fin = open("combnk.in", "r")
fout = open("combnk.out", "w")
str_count, one_count = [int(x) for x in fin.readline().split()]
ans = [0] * str_count

subset_k(0, 0)

fout.close()
