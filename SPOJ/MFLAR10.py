import sys

cases = sys.stdin.readlines()
for case in range(0, len(cases)-1):
	if cases[case] == '\n':
		continue
	var = cases[case].split()
	var[-1] = var[-1].strip('\n')
	val = var[0]
	val = val.upper()
	val = val[0]
	flag = 1
	for j in range(1, len(var)):
		temp = var[j].upper()
		if val != temp[0]:
			flag  = 0
			break
	if flag == 1:
		print'Y'
	else:
		print 'N'
