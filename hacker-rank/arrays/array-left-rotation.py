# Problem URL: https://www.hackerrank.com/challenges/array-left-rotation
# Enter your code here. Read input from STDIN. Print output to STDOUT
n,k = map(int, raw_input().split())
a = map(int, raw_input().split())
if k > n:
  k = k%n
if k%n != 0:
  b = list(a)
  for i in range(n):
    index = (i-k+n)%n
    b[index] = a[i]
  a = b
for i in range(len(a)):
    print a[i],