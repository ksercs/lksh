import sys


def hanoy(count, start, finish, temp):
    if (count == 1):
        print(start, finish, file=fout)
        return 1, start, finish
    
    else:
        hanoy(count - 1, start, temp, finish)
        print(start, finish, file=fout)
        hanoy(count - 1, temp, finish, start)


start = 1 
finish = 2
temp = 3
fin = open("hanoi.in", "r")
fout = open("hanoi.out", "w")
sys.setrecursionlimit(100000)   
count = int(fin.readline())
hanoy(count, start, finish, temp)

fout.close()