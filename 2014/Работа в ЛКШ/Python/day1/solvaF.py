name = list(input())
hard = input().split()
tabu = [int(x) for x in input().split()] 
like = input()
for i in range(len(name)):
            for j in range(len(hard)):
                        if name[i] == hard[j] and (not i in tabu):
                                    name[i] = like     
print(''.join(name))

