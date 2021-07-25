fin = open("muggers.in", "r")
fout = open("muggers.out", "w")

footstep_count, footstep_board = [int(x) for x in fin.readline().split()]

prices = [0] + list(map(int, fin.readline().split()))
  
for i in range(1, footstep_count + 1):
    prices[i] = min(prices[max(0, i - footstep_board - 1):i]) + prices[i]

    
print(prices[footstep_count], file=fout)

fout.close()