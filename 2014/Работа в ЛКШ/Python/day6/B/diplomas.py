def bin_search(x):
    left = 0
    right = height * count  
    while (right - left) > 1:
        mid = (right + left) // 2
        if (mid // wide) * (mid // height) < x:
            left = mid
        else:
            right = mid
    return right


fin = open("diplomas.in", "r")
fout = open("diplomas.out", "w")

wide, height, count  = list(map(int, fin.readline().split()))
if wide > height:
    wide, height = height, wide
print(bin_search(count), file=fout)
            
fout.close()