def is_prime(chisla):
  if chisla == 2:
    fl = True
  else:
    i = 1
    fl = True
    while i ** 2 <= chisla and fl:
      i += 1
      if chisla % i == 0:
          fl = False
          break
  return fl
 
 
chisla = int(input())
print(is_prime(chisla))