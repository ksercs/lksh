fin = open("snake.in", "r")
fout = open("snake.out", "w")

ch = int(fin.readline())
matrix = [[0] * ch for i in range(ch)]
number = 1
for i in range(1, ch + 1):
    for j in range(1, ch + 1):
        if i % 2 != 0:
            matrix[i - 1][j - 1] = number
            number += 1
            if j == ch:
                number += (ch - 1)
            
        else:
            matrix[i - 1][j - 1] = number
            if j == ch:
                    number += ch
            else:
                number -= 1
        
for i in range(1, ch + 1):
    print(file=fout)
    for j in range(1, ch + 1):
        print(matrix[i - 1][j - 1],  end=' ', file=fout)
            
fout.close()
