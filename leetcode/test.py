c = {}
patt = 'abba'
string = "dog cat cat dog"
strArray = string.split()
print(strArray)
for i in range(len(patt)):
	if patt[i] not in c.keys():
		c[patt[i]] = strArray[i]
	else:
		if strArray[i] != c[patt[i]]:
			print('false, pattern does not continue')
			break
print('true, pattern continued')
