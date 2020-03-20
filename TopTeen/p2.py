n1, n2 = raw_input().split()
n1 = int(n1)
n2 = int(n2)

if n1 == n2:
	print("Nivel Optimo")
elif n1 > n2:
	print ("2 " + str(n1 - n2))
else:
	print ("1 " + str(n2 - n1))
