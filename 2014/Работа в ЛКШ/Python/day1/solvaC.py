word = input()
if word[-1:len(word)]=='s': 
    word +=word[-2:len(word)]
if len(word) > 10:
    word *= 2
print(word)
