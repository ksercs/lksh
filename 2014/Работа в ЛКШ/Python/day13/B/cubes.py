fin = open("cubes.in", "r")
fout = open("cubes.out", "w")
count_Masha, count_Pasha = list(map(int, fin.readline().split()))
number_Masha = []
number_Pasha = []
for i in range(count_Masha):
    color_Masha = int(fin.readline())
    number_Masha.append(color_Masha)
for i in range(count_Pasha):
    color_Pasha = int(fin.readline())
    number_Pasha.append(color_Pasha)
number_Pasha = set(number_Pasha)
number_Masha = set(number_Masha)
print(len(number_Masha & number_Pasha) , file=fout)
print(*list(sorted(number_Masha & number_Pasha)), file=fout)
print(len(sorted(number_Masha - (number_Masha & number_Pasha))), file=fout)
print(*list(sorted(number_Masha - (number_Masha & number_Pasha))), file=fout)
print(len(sorted(number_Pasha - (number_Masha & number_Pasha))), file=fout)
print(*list(sorted(number_Pasha - (number_Masha & number_Pasha))), file=fout)

fout.close()