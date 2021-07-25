def subset(sel_set, un_set):
    if len(un_set) == 0:
        if len(sel_set) != 0:
            print(len(sel_set), *sel_set, file=fout)
    else:
        subset(sel_set + un_set[0:1], un_set[1:])
        subset(sel_set, un_set[1:])

fin = open("subsequences.in", "r")
fout = open("subsequences.out", "w")

ch = int(fin.readline())
sel_set = []
un_set = []
for i in range(1, ch + 1):
    un_set.append(i)
    
subset(sel_set, un_set)

fout.close()