# Problem URL: https://www.hackerrank.com/challenges/sparse-arrays
n = int(raw_input())
strings = {}
for i in range(n):
  s = raw_input()
  if s not in strings.keys():
    strings[s] = 1
  else:
    strings[s] += 1
q = int(raw_input())
for i in range(q):
  s = raw_input()
  if s not in strings.keys():
    print 0
  else:
    print strings[s]