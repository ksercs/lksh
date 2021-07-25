def reverse(x):
    str = int(fin.readline())
    if x > 1:
        reverse(x - 1)
    print(str, end=' ', file=fout)
    


fin = open("reverse.in", "r")
fout = open("reverse.out", "w")
import sys

ch = int(fin.readline())
sys.setrecursionlimit(10000)
reverse(ch)   

fout.close()