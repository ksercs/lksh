fin = open("dig-root.in", "r")
fout = open("dig-root.out", "w")

arr = [int(x) for x in fin.readline().split()]
#print(arr, end=' ', file=fout)

fout.close()