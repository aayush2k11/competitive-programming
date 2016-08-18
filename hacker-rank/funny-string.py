# Problem URL: https://www.hackerrank.com/challenges/funny-string
tc = int(raw_input())
for k in range(tc):
  s = raw_input()
  r = s[::-1]
  flag = 0
  for i in range(1, len(s)):
    if abs(ord(s[i])-ord(s[i-1])) != abs(ord(r[i])-ord(r[i-1])):
      flag = 1
      break
  if flag:
    print "Not Funny"
  else:
    print "Funny"