raw_input()
numbers = map(int, raw_input().split())

isGood = True
last = -99999999999
for n in numbers:
	if n <= last:
		isGood = False
		break
	last = n
if isGood:
	print ("SI")
else:
	print ("NO")