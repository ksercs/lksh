def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

a, b = [int(x) for x in input().split()]
lcm = a * b // gcd(a, b)
print(lcm)

