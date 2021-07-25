belt_long, str_count = [int(x) for x in input().split()] 
customer_count = int(input())
goods = [int(x) for x in input().split()] 

ans = 0

for i in range(len(goods)):
    ans += goods[i] * str_count
    if ans == belt_long:
        print(i + 1)
        break
    elif ans > belt_long:
        print(i)
        break
else:
    print(customer_count)
    
        
        
    
