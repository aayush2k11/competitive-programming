# Comment
n,k,q = map(int, raw_input().split())
a = map(int, raw_input().split())
if k > n:
  k = k%n
if k%n != 0:
  b = list(a)
  for i in range(n):
    index = (i+k)%n
    b[index] = a[i]
  a = b
for i in range(q):
  ind = int(raw_input())
  print a[ind]
