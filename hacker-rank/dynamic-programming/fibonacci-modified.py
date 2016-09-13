# Probelm URL: https://www.hackerrank.com/challenges/fibonacci-modified
t1, t2, n = map(int, raw_input().split())
array = [t1, t2]
for i in range(2,n):
  num = array[i-2] + array[i-1]**2
  array.append(num)
print array[n-1]