fin = open("collect.in", "r")
fout = open("collect.out", "w")


count_vid = int(fin.readline())
vid = [int(x) for x in fin.readline().split()]
vid = [0] + vid[:]

count_know = int(fin.readline())
know = [int(x) for x in fin.readline().split()]


def bin_search(left, right, x):
    while (right - left) > 1:
        m = (right + left) // 2
        if vid[m] < x:
            left = m
        else:
            right = m
    return vid[right]

for x in know:       
    if bin_search(0, len(vid) - 1, x) == x:
        print('YES', file=fout) 
    else:
        print('NO', file=fout) 
            
fout.close()