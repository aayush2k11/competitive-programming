n = int(raw_input())
for i in range(n):
  s = raw_input()
  flag = -1
  for i in range(len(s) - 1):
    if s[i] < s[i+1]:
      flag = i
  if flag == -1:
    print "no answer"
  else:
    first = s[flag]
    second = s[flag+1]
    s = s.replace(s[flag], second)
    s = s.replace(s[flag+1], first)
    print s