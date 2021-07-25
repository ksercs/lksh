fin = open("pants.in", "r")
fout = open("pants.out", "w")
count = int(fin.readline())
numbers = list(map(int, fin.readline().split()))
print(len(set(numbers)), file=fout)

fout.close()