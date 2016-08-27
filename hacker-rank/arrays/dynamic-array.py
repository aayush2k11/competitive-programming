# Problem URL: https://www.hackerrank.com/challenges/dynamic-array
n,q = map(int, raw_input().split())
arr = []
for i in range(n):
  arr.append([])
lastAns = 0
for i in range(q):
  k,x,y = map(int, raw_input().split())
  if k == 2:
    seq = (x^lastAns)%n
    lastAns = arr[seq][y%(len(arr[seq]))]
    print lastAns
  elif k == 1:
    seq = (x^lastAns)%n
    arr[seq].append(y)