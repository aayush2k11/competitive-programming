# Problem URL: https://www.hackerrank.com/contests/101hack40/challenges/lazy-mayor-and-lasers
n = int(raw_input())
height = map(int, raw_input().split())
m = int(raw_input())
lasers = map(int, raw_input().split())
lasers.sort()
for i in range(len(lasers)):
  start=0; end=0;
  if i == 0:
    start = 0
    end = lasers[i]-1
  else:
    start = lasers[i-1] - 1
    end = lasers[i] - 1
  for j in range(start, end):
    height[j] = max(min(end - j, height[j]), 0)
print sum(height)