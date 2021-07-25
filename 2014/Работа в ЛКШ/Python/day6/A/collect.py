def bin_search(left, right, x):
    while (right - left) > 1:
        m = (right + left) // 2
        if spec[m] < x:
            left = m
        else:
            right = m
    return spec[right]


fin = open("collect.in", "r")
fout = open("collect.out", "w")


count_spec = int(fin.readline())
spec = [int(x) for x in fin.readline().split()]
spec = [0] + spec[:]

count_know = int(fin.readline())
know = [int(x) for x in fin.readline().split()]

for x in know:       
    if bin_search(0, len(spec) - 1, x) == x:
        print('YES', file=fout) 
    else:
        print('NO', file=fout) 
            
fout.close()