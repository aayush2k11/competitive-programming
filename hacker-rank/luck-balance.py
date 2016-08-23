# Enter your code here. Read input from STDIN. Print output to STDOUT
n,k = map(int, raw_input().split())
count =0
important = []
i = 0
for i in range(n):
    l,t = map(int, raw_input().split())
    if t == 1:
        important.append(l)
    else:
        count += l
important.sort()
important = important[::-1]
print important
for i in range(k):
    count += important[i]
for j in range(i+1,len(important)):
  count -= important[j]
print count