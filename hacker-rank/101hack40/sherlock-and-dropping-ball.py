#Probelm URL: https://www.hackerrank.com/contests/101hack40/challenges/sherlock-and-dropping-ball
n,q = map(int, raw_input().split())
lines = []
for i in range(n):
  x1,y1,x2,y2 = map(int, raw_input().split())
  if (x1 < x2):
    lines.append([(x1,y1), (x2, y2)])
  else:
    lines.append([(x2,y2), (x1, y1)])
for i in range(q):
  x,y = map(int, raw_input().split())
  for i in lines:
    x1 = i[0][0]
    y1 = i[0][1]
    x2 = i[1][0]
    y2 = i[1][1]
    if x >= x1 and x <= x2:
      if y1>y2:
        print x2
      else:
        print x1
      break