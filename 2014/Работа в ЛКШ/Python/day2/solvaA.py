def printlist(s, before, between, after):
    print(before + between.join(s) + after)


s = input().split()
printlist(s, 'x=', '*', '.')
printlist(s, '', ' ', '')
printlist(s, '', '', '')
printlist(s, '"', '","', '"')







    
    
    
