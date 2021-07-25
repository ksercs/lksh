import sys


def power(os, st):
    if (st == 0):
        return 1
    else: 
        if (st % 2 == 0):
            return (power(os, st // 2) ** 2) % m
        else:
            return (power(os, st - 1) * os) % m 


fin = open("power.in", "r")
fout = open("power.out", "w")
sys.setrecursionlimit(100000)        
os, st, m = [int(x) for x in fin.readline().split()]
# print(arr, end=' ', file=fout)
# print(os, st, m, end=' ', file=fout)
print(power(os, st), file=fout)

fout.close()