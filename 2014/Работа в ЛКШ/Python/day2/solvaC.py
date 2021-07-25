def prime(ch):
    i = 2
    div = []
    while ch > 1:
        if ch % i == 0:
            ch //= i
            div.append(i)
        else:
            i += 1
            if i * i > ch:
                div.append(ch)
                break
    return div

x = int(input())
arr = prime(x)

for j in arr:
        print(j, end = ' ')    
        
