def gcd(a, b):
    while b != 0:
        a, b = b, a % b
        a = gcd(a, b)
    return a

      
lst = [int(x) for x in input().split()]

ans = lst[0]
if len(lst) > 1:
    for i in lst:
        ans = gcd(ans, i)
print(ans)





    
    