def subset_k(food_count, max_food, prefix):
    if max_food == 0:
        print(prefix, file=fout)
    else:
        if len(prefix) == 0:
            nextt = 1
        else:
            nextt = prefix[-1] + 1
        while nextt + max_food - 1 <= food_count:
            subset_k(food_count, max_food - 1, prefix + [nextt])
            nextt += 1
            
fin = open("dinner.in", "r")
fout = open("dinner.out", "w")
food_count, max_food = [int(x) for x in fin.readline().split()]
for i in range(max_food + 1):
    subset_k(food_count, i, [])

fout.close()