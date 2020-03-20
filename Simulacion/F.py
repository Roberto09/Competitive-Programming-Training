import math
from decimal import *
n = 0.0
res  = 0.0
t = 0
toAdd = 0
ans = []
ans2 = []

t = int(raw_input())

for i in range(t):
	n = Decimal(raw_input())
	ans = []
	for j in range(8):
		toAdd = int(math.floor(n))
		ans.append(toAdd)
		n = Decimal(n - Decimal(toAdd))
		n = Decimal(Decimal(1.0)/n)
	num = 1
	den = ans[7]
	aux = 0
	for j in range(7):
		jj = 6 - j
		num += ans[jj] * den
		aux = num
		num = den
		den = aux
	res = ""
	for i in range(7):
		res += str(ans[i]) + " "
	res += str(ans[7])
	print (res)
	print(str(den) + "/" + str(num))