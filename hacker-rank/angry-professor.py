t = int(raw_input())
for i in range(t):
  n,k = map(int, raw_input().split())
  count = 0
  students = map(int, raw_input().split())
  for i in students:
    if i <=0 :
      count += 1
  if count < k:
    print "YES"
  else:
    print "NO"